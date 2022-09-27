function [J, grad] = lrCostFunction(theta, X, y, lambda)
m = length(y);
J = -(y' * log(sigmoid(X * theta)) + (1-y)' * log(1 - sigmoid(X*theta)))/m;
grad = (X' *  (sigmoid(X*theta) - y))/m;
J = J + (lambda/(2*m)) * (theta(2:end)' * theta(2:end));
grad(2:end) = grad(2:end) + (lambda/m) * theta(2:end);
end
