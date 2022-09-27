# Step 1: Import libraries
import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split
from matplotlib import pyplot as plt

# Step 2: Get the dataset
df = pd.read_csv('Demo_Data.csv')


# Separate Data into labels using 'iloc' function
x_1 = df.iloc[:,0]
x_2 = df.iloc[:,1]
y = df.iloc[:,2]

# Step 3: Split data for training and testing
train, test = train_test_split(df, test_size=0.2)
x_train = train.iloc[:,0:2]
x1_train = train.iloc[:,0]
x2_train = train.iloc[:,1]
x_test = test.iloc[:,0:2]
x1_test = test.iloc[:,0]
x2_test = test.iloc[:,1]

y_train = train.iloc[:,2]
y_test = test.iloc[:,2]

print(y_train.head(5))

# Step 4: Create a model and fit data

linear_reg = LinearRegression()
linear_reg.fit(x_train.values, y_train.values)
print(linear_reg.coef_)

# Make predictions 
prediction = linear_reg.predict(np.array([[1499,0.725400244]]))[0]
print(prediction)