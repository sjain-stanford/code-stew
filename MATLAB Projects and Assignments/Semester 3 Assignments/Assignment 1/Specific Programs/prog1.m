clc;
clear all;
close all;
disp('The loop equations are:');
disp('18i-4j-8k=10');
disp('4i-12j+2k=0');
disp('8i+2j-25k=0');
R=[18 -4 -8;4 -12 2;8 2 -25]
V=[10;0;0]
disp('And we know, V*I=R');
disp('Thus I=inv(V)*R');
disp('Thus the current i,j,k in the loops are:');
I=inv(R)*V