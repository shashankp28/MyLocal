function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
m = length(y);
J_history = zeros(num_iters, 1);
for iter = 1:num_iters
    delta = zeros(2, 1);
    for i = 1:m
        delta = delta + (X(i,:)*theta - y(i)) * X(i,:)';
    end
    theta = theta - alpha*delta/m;
    J_history(iter) = computeCost(X, y, theta);
end
end
