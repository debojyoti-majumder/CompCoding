// This sample Node.js program which uses the tfjs version which is slowest of them all

// Obtaining the package for tensorflow JS
const tf = require('@tensorflow/tfjs');

// This is the model which would be used later 
const model = tf.sequential()

// As for now using a single layer, just have one nuron
const layer1 = tf.layers.dense({units:1,inputShape:[1]});
model.add(layer1);

// finalizing the model
model.compile({optimizer:'sgd', loss:'meanSquaredError'});
model.summary();

async function trainInput(inputData, outputData) {
    const modelOutput = await model.fit(inputData, outputData, {
        epochs:500,
        callbacks: {
            onEpochEnd: async(epochs, logs) => {
                console.log("Epoch# ", epochs, " Loss:", logs.loss);
            }
        }
    });
}

console.log("Training the model now..");
const xs = tf.tensor2d([-1.0, 0.0, 1.0, 2.0, 3.0, 4.0], [6,1]);
const ys = tf.tensor2d([-3.0, -1.0, 2.0, 3.0, 5.0, 7.0], [6,1]);

// Initiating the training model
trainInput(xs,ys).then(() => {
    // The predict function is called after the taining has been done
    const predInp = tf.tensor2d([10,12], [2,1]);
    const output = model.predict(predInp);

    // Verbsoe output
    console.log(output.toString());
});

console.log('Press any key to exit');

process.stdin.setRawMode(true);
process.stdin.resume();
process.stdin.on('data', process.exit.bind(process, 0));
