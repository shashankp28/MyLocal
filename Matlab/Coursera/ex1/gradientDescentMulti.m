function [theta, J_history] = gradientDescentMulti(X, y, theta, alpha, num_iters)
m = length(y);
J_history = zeros(num_iters, 1);
for iter = 1:num_iters
    delta = zeros(length(theta), 1);
    for i=1:m
        delta = delta + (X(i,:)*theta - y(i,:))*X(i,:)';
    end
    theta = theta - (alpha/m)*delta;
    J_history(iter) = computeCostMulti(X, y, theta);
end
end
