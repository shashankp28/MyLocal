# Step 1: Import libraries
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn import metrics

# Step 2: Get the dataset
df = pd.read_csv("Data.csv")
print(df.iloc[0:10])

# Separate Data into labels using 'iloc' function
x_1 = df.iloc[:, 0]
x_2 = df.iloc[:, 1]
X = df.iloc[:, 0:2]
Y = df.iloc[:, 2]

print(X[0:10])

# Step 3: Split data for training and testing
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=0)

# Step 4: Create a model and fit data (y = theta_0 + theta_1*x_1 + theta_2*x_2)
reg = LinearRegression()
reg.fit(X_train, Y_train)
print("theta_0 =", reg.intercept_)
print("theta_1 =", reg.coef_[0])
print("theta_2 =", reg.coef_[1])
print()
print("y = theta_0 + theta_1*x_1 + theta_2*x_2")
print()

# Step 5: Make predictions 
Y_pred = reg.predict(X_test)
pred_data = pd.DataFrame({"Actual":Y_test, "Predicted:":Y_pred})
print(pred_data.iloc[0:10])
print()
print("Cost:", metrics.mean_squared_error(Y_test, Y_pred))
print(np.mean(Y_test - Y_pred))
