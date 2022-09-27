function [J, grad] = costFunctionReg(theta, X, y, lambda)
m = length(y);
[J, grad] = costFunction(theta, X, y);
J  = J + lambda * (sum(theta(2:end).^2))/(2*m);
grad(2:end) = grad(2:end) + lambda * theta(2:end)/m;
end
