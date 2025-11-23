function [ phi ] = prototypr_fcn(n,T)
% PROTOTYPE_FCN - This function can be used to calculate 
% phi_n and its derivatives. The matrix phi has in its first row the
% polynomial coefficients of phi_n and in the following rows its
% derivaties. The parameter T represents the transit duration and the
% constant n is equal to the number of computed derivaties. The transition
% is going in tau = t/T from 0 to 1.
% How to use the function:
%   phi = prototype_fcn(n,T)
%

phi = zeros(n+1,2*n+2); % Definition of the matrix size: n x 2*n+1


%% Calculation by the formula from the lecture
% First row of phi = coefficients of the polynomial
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Term within the sum on the correct column of the row-vector

for k = 0:n
    phi(1,n+1-k) = nchoosek(n,k)*(-1)^k/(n+k+1);
end

% Add factor (which is multiplied by the sum) to all coefficients
phi = factorial(2*n+1)/factorial(n)^2*phi;

%% calculate j-th derivative and put the coefficients in the (j+1)-th row.
% Comute all other rows
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

for j = 1:n
phi(j+1,j+1:end) = 1/T*polyder(phi(j,j:end));
end
end