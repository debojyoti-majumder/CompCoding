# This would add hidden layers with drop outs, generally there is no need to run 200 epochs
# model kind of happens to be at a good state after 60 epochs

# TODO: Save the model information, put it through the forward pass and  
# predict gieven the mnist data given as input
from __future__ import print_function

import numpy as np
from numpy.core.fromnumeric import reshape
from numpy.ma.core import shape
from pylint import utils

from keras.datasets import mnist
from keras.layers.core import Activation, Dense, Dropout
from keras.models import Sequential
from keras.optimizers import SGD
from keras.utils import np_utils

# Used for result reproduction
np.random.seed(7135)

# Vital parametrs for the program to run
VERBOSE = 1
NB_EPOCH = 200
NB_HIDDEN = 128
DROPOUT_RATE = 0.2

#Stage 1: Preparing the data for the model
(X_train, y_train),(X_test, y_test) = mnist.load_data()
X_train_shape = X_train.shape
X_test_shape = X_test.shape

print("Shape of the orginal training set")
print(X_train_shape)

# X_train is a matrix of 60000x784 ( 784 is rehaped from 28x28)
reshaped_lenght = X_train_shape[1] * X_train_shape[2]

#Reshaping the dataset
X_train = X_train.reshape(X_train_shape[0], reshaped_lenght)
X_test = X_test.reshape(X_test.shape[0], reshaped_lenght)

if VERBOSE:
    print("After transforming the dataset")
    print(X_train.shape)
    print(X_test.shape)

# Scaling the values of the dataset, should remove the hardcodings
X_train = X_train.astype('float32')
X_test = X_test.astype('float32')
X_train /= 255
X_test /= 255

# Performing one hot encoding
NB_CLASSES = 10
Y_train = np_utils.to_categorical(y_train, NB_CLASSES)
Y_test = np_utils.to_categorical(y_test, NB_CLASSES)

if VERBOSE:
    print("Sample ouput vector one hot encoded")
    print(Y_train[0])

# Stage 2.1: Building the model
model = Sequential()

# Input layer
model.add(Dense(NB_HIDDEN,input_shape=(reshaped_lenght,)))
model.add(Activation('relu'))
model.add(Dropout(DROPOUT_RATE))

# Hidden layer
model.add(Dense(NB_HIDDEN))
model.add(Activation('relu'))
model.add(Dropout(DROPOUT_RATE))

# Output layer
model.add(Dense(NB_CLASSES))
model.add(Activation('softmax'))

if VERBOSE:
    model.summary()

# Stage 2.2 Compling the model
# Using Stocatic gradient decent optimizer
OPTIMIZER = SGD()
model.compile(loss='categorical_crossentropy', optimizer=OPTIMIZER, metrics=['accuracy'])

# Stage 2.3 Traning
BATCH_SIZE = 128
history = model.fit(X_train, Y_train, batch_size=BATCH_SIZE,
            epochs=NB_EPOCH, verbose=VERBOSE, validation_split=0.2)
print("----------------- Training done------------------")

# Stage 2.4 Final evaluation with the test set
score = model.evaluate(X_test, Y_test, verbose=VERBOSE)
print("Test socre:", score[0])
print("Test accuracy", score[1])
