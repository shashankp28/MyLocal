function p = predict(Theta1, Theta2, X)
m = size(X, 1);
p = zeros(size(X, 1), 1);
X = [ones(m, 1) X];
a_2 = sigmoid(X * Theta1');
a_2 = [ones(m, 1) a_2];
a_3 = sigmoid(a_2 * Theta2');
[M, p] = max(a_3, [], 2)
end
