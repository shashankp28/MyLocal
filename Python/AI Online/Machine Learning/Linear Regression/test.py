import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn import metrics
import numpy as np
data = pd.read_csv("Linear Regression - Sheet1.csv")
data.plot(x="X", y="Y", style="o")
plt.title("X vs Y")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()
sns.distplot(data["Y"])
plt.show()
X = data["X"].values.reshape(-1, 1)
Y = data["Y"].values.reshape(-1, 1)
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=0)
lreg = LinearRegression()
lreg.fit(X_train, Y_train)
print(lreg.coef_)
print(lreg.intercept_)
Y_pred = lreg.predict(X_test)
pred_data = pd.DataFrame({"Actual":Y_test.flatten(), "Predicted":Y_pred.flatten()})
print(pred_data)
pred_data.head(25).plot(kind="bar")
plt.show()
plt.scatter(X_test, Y_test, color="b")
plt.plot(X_test, Y_pred, color="r")
plt.show()
print("Mean absolute error:", metrics.mean_absolute_error(Y_test, Y_pred))
print("Mean squared error:", metrics.mean_squared_error(Y_test, Y_pred))
print("Root mean squared error:", np.sqrt(metrics.mean_squared_error(Y_test, Y_pred)))