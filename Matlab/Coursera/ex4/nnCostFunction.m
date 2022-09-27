function [J, grad] = nnCostFunction(nn_params, s, h, k, X, y, lambda)
    y = (1:k)==y;
    m = size(X, 1);
    Theta1 = [reshape(nn_params(1:h*(s+1)), h, s+1)];
    Theta2 = [reshape(nn_params(h*(s+1)+1:end), k, h+1)];

    %Forward Propagation
    a1 = [ones(size(X, 1), 1), X];
    z2 = a1 * Theta1';
    a2 = sigmoid(z2);
    a2 = [ones(size(a2, 1), 1), a2];
    z3 = a2*Theta2';
    a3 = sigmoid(z3);

    %Cost
    J = (1/m) * sum(sum((-y.*log(a3) + (y-1).*log(1-a3))));
    J = J + (lambda/(2*m)) * (sum(Theta1(:, 2:end).^2, 'all') + sum(Theta2(:, 2:end).^2, 'all'));
    %Backward Propagation
    d3 = a3 - y;
    d2 = (d3 * Theta2).*[ones(size(z2, 1), 1), sigmoidGradient(z2)];
    d2 = d2(:, 2:end);

    
    %Gradient
    Theta1_grad = (d2' * a1) / m;
    Theta2_grad = (d3' * a2) / m;
    Theta1_grad(:, 2:end) = Theta1_grad(:, 2:end) + (lambda/m) * Theta1(:, 2:end);
    Theta2_grad(:, 2:end) = Theta2_grad(:, 2:end) + (lambda/m) * Theta2(:, 2:end);

    grad = [Theta1_grad(:) ; Theta2_grad(:)];
end
