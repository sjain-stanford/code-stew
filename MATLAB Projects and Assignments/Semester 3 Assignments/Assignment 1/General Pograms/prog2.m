clear all;
close all;
clc;
%The circuit diagram is as shown.
I=zeros(1,3);
disp('Enter the three current sources I1,I2,I3:');
for i=1:3
    I(i)=input('');
end
R=zeros(1,6);
disp('Enter the six resistors R1,R2,R3,R4,R5,R6:');
for i=1:6
    R(i)=input('');
end
disp('Let the node 5 be grounded.');
disp('Applying KCL to the given circuit:');
r=[0 -1/R(1) 0 1/R(1)+1/R(6);-1/R(2) 1/R(1)+1/R(2)+1/R(3) -1/R(3) -1/R(1);-1/R(4) -1/R(3) 1/R(3)+1/R(4) 0;-1/R(2)-1/R(4) 1/R(2) 1/R(4) 0];
i=[I(1);I(2);I(3);I(1)];
%This variable v stores from V1 to V4 only.
v=inv(r)*i;
v(5)=0;
disp('The nodal voltages are:');
disp('V1=');
disp(v(1));
disp('V2=');
disp(v(2));
disp('V3=');
disp(v(3));
disp('V4=');
disp(v(4));
%Since the node 5 was grounded.
disp('V5=');
disp(v(5));
disp('V6=');
disp(-I(3)*R(5));