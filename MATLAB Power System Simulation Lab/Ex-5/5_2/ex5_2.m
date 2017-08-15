% Ex-5.2 (Power Systems)
% Sambhav R Jain
% 107108103

clc;
clear all;
close all;

fprintf('Ex-5.2 Zbus building algorithm\n');
fprintf(' - Sambhav R Jain (107108103)\n\n');

N = input('Enter the number of buses in the existing power system: ');

for m = 1:1:N
    for n = m:1:N
        Z(m,n) = input(sprintf('Enter the z(%d,%d): ',m,n));
        Z(n,m) = Z(m,n);
    end
end

fprintf('\nThe Zbus matrix is: \n');
Zold = 1i*Z

j = input('Enter the bus subscript "j" where the new branch is to be added: ');
k = input('Enter the bus subscript "k" where the new branch is to be added: ');
Zb = input(sprintf('Enter the impedance to be added between bus %d and %d: ',j,k));

for p = 1:1:N
    Z(N+1,p) = Z(k,p) - Z(j,p);
end

for q = 1:1:N
    Z(q,N+1) = Z(q,k) - Z(q,j);
end

Z(N+1,N+1) = Z(k,k) + Z(j,j) -2*Z(k,j) + Zb;
Zeq = Z(N+1,N+1);

% Kron reduction
for m = 1:1:N
    for n = 1:1:N
        Z(m,n) = Z(m,n) - (Z(N+1,n)*Z(m,N+1)/Zeq);
    end
end

% To eliminate the (N+1)th row and column
for m = 1:1:N
    for n = 1:1:N
        Znew(m,n) = Z(m,n);
    end
end

fprintf('\nThe new Zbus matrix is: \n');
Znew = 1i*Znew
