// Works on iris data set, Usage : node loadData.js -c -d "iris.csv"

const tf = require('@tensorflow/tfjs');
const commandLineArgs = require('command-line-args');

// This is to host the data file
const express = require('express');
const app = express();
const port = 3000;
app.use(express.static('data'));

// for command line parsing
const optionDefinitions = [
    { name: 'cpu', alias: 'c', type: Boolean, },
    { name: 'data', alias: 'd', type: String },
    { name: 'timeout', alias: 't', type: Number }
];

const parsedOptions = commandLineArgs(optionDefinitions);


// Optional dependency to have cpu accelaration
if( parsedOptions['cpu'] !== null && parsedOptions['cpu'] === true ) {
    const tfCpu = require('@tensorflow/tfjs-node');
    console.log("Using cpu accelaration tfjs-node:", tfCpu.version['tfjs-node']);
}

// The data option is needed of course to load the dataset.
if( parsedOptions['data'] !== null ) {
    app.listen(port, () => {
        console.log("Web server is running on port", port);

        const dataFile = parsedOptions['data'];
        const trainedModel = run(dataFile);
        console.log(trainedModel);    
    });    
} 

async function run(dataFile) {
    console.log("Running the model with data file", dataFile);
    const trainingData = tf.data.csv(dataFile, {
        columnConfigs: {
            species: {
                isLabel: true
            }
        }
    });
    
    const numOfFeatures = (await trainingData.columnNames()).length - 1;
    const convertedData = trainingData.map(({xs, ys}) => {
              const labels = [
                    ys.species == "setosa" ? 1 : 0,
                    ys.species == "virginica" ? 1 : 0,
                    ys.species == "versicolor" ? 1 : 0
              ] 
              return{ xs: Object.values(xs), ys: Object.values(labels)};
          }).batch(15);
    
    const model = tf.sequential();
    model.add(tf.layers.dense({inputShape: [numOfFeatures], activation: "sigmoid", units: 5}))
    model.add(tf.layers.dense({activation: "softmax", units: 3}));
    
    model.compile({loss: "categoricalCrossentropy", optimizer: tf.train.adam(0.06)});
    
    await model.fitDataset(convertedData, 
                     {epochs:200,
                      callbacks:{
                          onEpochEnd: async(epoch, logs) =>{
                              console.log("Epoch: " + epoch + " Loss: " + logs.loss);
                          }
                      }});
    return model
}
