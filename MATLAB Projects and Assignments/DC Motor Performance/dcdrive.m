% Industrial Electronics Assignment
% Sambhav R Jain
% 107108103

clc;
clear all;
close all;

fprintf('Performance Analysis of a single phase separately excited DC motor drive - Analytical Solution\n');
fprintf(' - Sambhav R Jain (107108103)\n\n');

% fprintf('Enter the following parameters:\n');
% V = input('Supply rms voltage (V): ');
% Ra = input('Enter the armature resistance (Ohm): ');
% La = input('Enter the armature inductance (Henry): ');
% f = input('Enter the supply frequency (Hz): ');
% del_i = input('Enter the maximum current error (A): ');
% del_alpha = input('Enter the incremental alpha (deg): ');
% alpha_max = input('Enter the maximum firing angle (deg): ');

V = 110;
Ra = 0.6;
La = 6e-3;
f = 50;
del_i = 0.001;
del_alpha = deg2rad(15);
alpha_max = deg2rad(150);

Vm = sqrt(2)*V;

w = 2*pi*f;
Z = sqrt(Ra^2 + (w*La)^2);
theta_z = atan(w*La/Ra);
alpha = 0;
alpha = deg2rad(alpha);
N = 1;
while 1  
    Eg = Vm*N;
    if(Eg < Vm*sin(alpha))
        if(alpha < pi/2)
            break
        end
    end
    N = N - 0.0001;
end

theta_s = max(alpha,asin(Eg/Vm));
Ia_s = 0;
% A1 = (Ia_s - (Vm/Z)*sin(theta_s-theta_z) + Eg/Ra)*exp(Ra/(w*La)*theta_s);
Ia_pi = Vm/Z*(sin(pi-theta_z) - sin(theta_s-theta_z)*exp(Ra/(w*La)*(theta_s-pi))) + Eg/Ra*(exp(Ra/(w*La)*(theta_s-pi))-1) + Ia_s*exp(Ra/(w*La)*(theta_s-pi))
% A2 = (Ia_pi+Eg/Ra)*exp(Ra/w*La*pi);

ch = menu('Choose:','Semi-converter','Full-converter');
if ch == 1
      Ia_pi_alpha = Ia_pi*exp(Ra/(w*La)*(pi-pi-alpha)) + Eg/Ra*(exp(Ra/(w*La)*(pi-pi-alpha))-1)
      Ia_pi_theta_s = Ia_pi*exp(Ra/(w*La)*(pi-pi-theta_s)) + Eg/Ra*(exp(Ra/(w*La)*(pi-pi-theta_s))-1)
end
if ch == 2
    Ia_pi_alpha = Vm/Z*(sin(pi+alpha-theta_z) - sin(theta_s-theta_z)*exp(Ra/(w*La)*(theta_s-pi-alpha))) + Eg/Ra*(exp(Ra/(w*La)*(theta_s-pi-alpha))-1) + Ia_s*exp(Ra/(w*La)*(theta_s-pi-alpha))
    Ia_pi_theta_s = Vm/Z*(sin(pi+theta_s-theta_z) - sin(theta_s-theta_z)*exp(Ra/(w*La)*(theta_s-pi-theta_s))) + Eg/Ra*(exp(Ra/(w*La)*(theta_s-pi-theta_s))-1) + Ia_s*exp(Ra/(w*La)*(theta_s-pi-theta_s))   
end

if Ia_pi_alpha > 0
    if Ia_pi_theta_s > 0
        theta_s = alpha;
        while 1
            Ia_s = Ia_pi_alpha;
            % A1 = (Ia_s - (Vm/Z)*sin(theta_s-theta_z) + Eg/Ra)*exp(Ra/(w*La)*theta_s);
            Ia_pi = Vm/Z*(sin(pi-theta_z) - sin(theta_s-theta_z)*exp(Ra/(w*La)*(theta_s-pi))) + Eg/Ra*(exp(Ra/(w*La)*(theta_s-pi))-1) + Ia_s*exp(Ra/(w*La)*(theta_s-pi))
            % A2 = (Ia_pi+Eg/Ra)*exp(Ra/w*La*pi);
            I_old = Ia_pi_alpha;
            % ch = menu('Choose:','Semi-converter','Full-converter');
            if ch == 1
                Ia_pi_alpha = Ia_pi*exp(Ra/(w*La)*(pi-pi-alpha)) + Eg/Ra*(exp(Ra/(w*La)*(pi-pi-alpha))-1)
                Ia_pi_theta_s = Ia_pi*exp(Ra/(w*La)*(pi-pi-theta_s)) + Eg/Ra*(exp(Ra/(w*La)*(pi-pi-theta_s))-1)
            end
            if ch == 2
                Ia_pi_alpha = Vm/Z*(sin(pi+alpha-theta_z) - sin(theta_s-theta_z)*exp(Ra/(w*La)*(theta_s-pi-alpha))) + Eg/Ra*(exp(Ra/(w*La)*(theta_s-pi-alpha))-1) + Ia_s*exp(Ra/(w*La)*(theta_s-pi-alpha))
                Ia_pi_theta_s = Vm/Z*(sin(pi+theta_s-theta_z) - sin(theta_s-theta_z)*exp(Ra/(w*La)*(theta_s-pi-theta_s))) + Eg/Ra*(exp(Ra/(w*La)*(theta_s-pi-theta_s))-1) + Ia_s*exp(Ra/(w*La)*(theta_s-pi-theta_s))   
            end 
            abs(I_old - Ia_pi_alpha)
            if abs(I_old - Ia_pi_alpha) <= del_i
                break
            end
        end      
    
    end
end

        

    
    






