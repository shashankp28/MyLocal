function [X_norm, mu, sigma] = featureNormalize(X)
m = size(X, 1);
mu = repmat(mean(X), m, 1);
sigma = repmat(std(X), m, 1);
X_norm = (X-mu)./sigma;
mu = mu(1,:);
sigma = sigma(1,:);
end
