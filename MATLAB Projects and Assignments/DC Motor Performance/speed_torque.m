% Sambhav R Jain (107108103)
clc;
clear all;
close all;

V = input('Enter the rms voltage: ');
k_phi = input('Enter the field constant: ');
Ra = input('Enter the armature resistance: ');

td = 0:0.01:20;
Vm = sqrt(2)*V;

for a=0:30:150
    Va = Vm/pi*(1+cosd(a));
    w = Va/k_phi - td*Ra/k_phi^2;
    plot(td,w);
    xlabel('Torque(N-m) ---->'); ylabel('Speed (rad/s) ---->'); title('Speed torque for a separately excited dc motor for different firing angles');

    % legend(sprintf('alpha = %d',a));
    hold on
    grid
end