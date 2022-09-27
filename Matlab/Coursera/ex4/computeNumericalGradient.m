function numgrad = computeNumericalGradient(J, theta)
numgrad = zeros(size(theta));
perturb = zeros(size(theta));
eps = 1e-4;
for p = 1:numel(theta)
    perturb(p) = eps;
    loss1 = J(theta - perturb);
    loss2 = J(theta + perturb);
    numgrad(p) = (loss2 - loss1) / (2*eps);
    perturb(p) = 0;
end
end
