function p = predictOneVsAll(all_theta, X)
m = size(X, 1);
num_labels = size(all_theta, 1);
X = [ones(m, 1) X];
[M, p] = max(X * all_theta', [], 2);
end
