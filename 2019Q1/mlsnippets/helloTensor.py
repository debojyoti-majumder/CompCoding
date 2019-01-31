import tensorflow as tf;

# Declaring the session
helloConstant = tf.constant('Hello Tensorflow from deb')

# Running the computaion in a session
session = tf.Session()
print(session.run(helloConstant))