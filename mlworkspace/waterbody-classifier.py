# Dataset source: https://data.world/data-ny-gov/8xz8-5u5u/workspace/file?filename=waterbody-classifications-1.csv

import pandas as pd

# Loading data set as pandas data frame
filename = "waterbody-classifications-1.csv"
data = pd.read_csv(filename)

# Replaing NaN with mean 
data['Segment Miles'].fillna((data['Segment Miles'].mean()), inplace=True)

# Do not require index number, name
data.drop(columns="Waterbody Index Number (WIN)",inplace=True)
data.drop(columns="Segment ID", inplace=True)
data.drop(columns="Name", inplace=True)
data.drop(columns="Description", inplace=True)

#Verbose ouput
print(data.sample(n=10))