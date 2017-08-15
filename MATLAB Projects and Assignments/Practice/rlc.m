function x_dot = rlc(t,x)
R = 1;
L = 1;
C = 1;

x_dot(1,1) = - R/L * x(1) - 1/(L*C) * x(2);
x_dot(2,1) = - L/R * x_dot(1,1) - 1/(R*C) * x(2);  