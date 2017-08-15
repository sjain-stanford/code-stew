clc;
clear all;
close all;
v=15;
r=6;
disp('The Thevenin voltage is : 15V');
disp('The Thevenin resistance is : 6 ohms');
disp('If load resistance varies from (0-12)ohms');
for R=0:2:12
    I(1,(R/2)+1)=15/(6+R);
end
R=[0 2 4 6 8 10 12];
disp('Power dissipated varies as:');
P=(I.^2).*R
plot(R,P);
xlabel('Load Resistance');
ylabel('Power dissipated');
disp('Maximum power dissipated is: 9.3750 Watts');
disp('Maximum power is dissipated at 6 ohms load');
 

