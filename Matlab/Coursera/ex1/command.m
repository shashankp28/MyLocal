data = load('ex1data2.txt');
X = data(:, 1:2);
y = data(:, 3);
m = length(y);
X = [ones(m,1), X];
theta = normalEqn(X, y);
fprintf('Theta computed from the normal equations:\n%f\n%f\n%f', theta);
[1 1650 3]*theta
