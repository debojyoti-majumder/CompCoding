// Works on iris data set, Usage : node loadData.js -c -d "iris.csv"

const tf = require('@tensorflow/tfjs');

// for command line parsing
const commandLineArgs = require('command-line-args')
const optionDefinitions = [
    { name: 'cpu', alias: 'c', type: Boolean, },
    // { name: 'src', type: String, multiple: true, defaultOption: true },
    { name: 'data', alias: 'd', type: String },
    { name: 'timeout', alias: 't', type: Number }];

const parsedOptions = commandLineArgs(optionDefinitions);
process.stdin.setRawMode(true);
process.stdin.resume();
process.stdin.on('data', process.exit.bind(process, 0));

// Optional dependency to have cpu accelaration
if( parsedOptions['cpu'] !== null && parsedOptions['cpu'] === true ) {
    const tfCpu = require('@tensorflow/tfjs-node');
    console.log("Using cpu accelaration tfjs-node:", tfCpu.version['tfjs-node']);
}

// The data option is needed of course to load the dataset.
if( parsedOptions['data'] !== null ) {
    const dataFile = parsedOptions['data'];
    run(dataFile);
} 

async function run(dataFile) {
    console.log("Running the model with data file", dataFile);

    const trainingData = tf.data.csv(dataFile,{
        columnConfigs: {
            species: { isLable: true }     
        }
    });

    const batchSize = 10;
    const numberOfFeatures = 4;

    // This is been done as one hot encoding
    const convertedData = trainingData.map(({xs,ys}) => {
        const labels = [
            ys.species == "setosa" ? 1 : 0,
            ys.species == "virginica" ? 1 : 0,
            ys.species == "versicolor" ? 1 : 0 
        ]

        return {xs:Object.values(xs), ys:Object.values(labels)};
    }).batch(batchSize);

    const model = tf.sequential();
    const inputLayer = tf.layers.dense({
        inputShape: [numberOfFeatures],
        activation: 'sigmoid',
        units: 5
    });

    // 3 because the of number species
    const outputLayer = tf.layers.dense({
        activation: 'softmax',
        units: 3
    });

    model.add(inputLayer);
    model.add(outputLayer);

    model.compile({
        loss: "categoricalCrossentropy",
        optimizer: tf.train.adam(0.05)
    });

    await model.fitDataset(
        convertedData,
        {
            epochs: 200,
            callbacks: {
                onEpochEnd: async(epoch, logs) => {
                    console.log("Epoch# " + epoch + "Loss: " + logs.loss);
                }
            }
        }  
    );
    console.log(trainingData, convertedData);
}
