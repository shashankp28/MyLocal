data = load("ex2data2.txt");
X = data(:, [1, 2]);
y = data(:, 3);
X = mapFeature(X(:, 1), X(:, 2));
theta = zeros(size(X, 2), 1);
lambda = 100;
[cost, grad] = costFunctionReg(theta, X, y, lambda);
options = optimoptions(@fminunc, 'Algorithm', 'Quasi-Newton', 'GradObj', 'on', 'MaxIter', 400);
[theta, cost, exitFlag] = fminunc(@(t)(costFunctionReg(t, X, y, lambda)), theta, options);
plotDecisionBoundary(theta, X, y);
p = predict(theta, X);
mean(mean(double(p==y))*100)
