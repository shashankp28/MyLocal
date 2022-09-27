import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn import metrics
import numpy as np
#take input of csv
data = pd.read_csv("weather.csv")
#plot x and y
data.plot(x="MinTemp", y="MaxTemp", style="o")
plt.title("MinTemp vs MaxTemp")
plt.xlabel("MinTemp")
plt.ylabel("MaxTemp")
plt.show()
#probabilty density function
sns.distplot(data["MaxTemp"])
plt.show()
X = data["MinTemp"].values.reshape(-1, 1)
Y = data["MaxTemp"].values.reshape(-1, 1)
#train test split
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=0)
#actual regression
reg = LinearRegression()
reg.fit(X_train, Y_train)
print(reg.intercept_)
print(reg.coef_)
Y_pred = reg.predict(X_test)
pred_data = pd.DataFrame({"Actual":Y_test.flatten(), "Predicted:":Y_pred.flatten()})
print(pred_data)
pred_data.head(25).plot(kind="bar")
plt.show()
plt.scatter(X_test, Y_test, color="blue")
plt.plot(X_test, Y_pred, color="red")
plt.title("MinTemp vs MaxTemp")
plt.xlabel("MinTemp")
plt.ylabel("MaxTemp")
plt.savefig("img1.jpg")
plt.show()
print("Mean Absolute Error:", metrics.mean_absolute_error(Y_test, Y_pred))
print("Mean Squared Error:", metrics.mean_squared_error(Y_test, Y_pred))
print("Root mean squared Error:", np.sqrt(metrics.mean_squared_error(Y_test, Y_pred)))