% Ex-3.2 (Transmission System)
% Sambhav R Jain
% 107108103

clc;
clear all;
close all;

fprintf('Ex-3.2 Medium Transmission Line (nominal T model)\n');
fprintf(' - Sambhav R Jain (107108103)\n\n');

V = input('Enter the receiving end line-line voltage (kV): ');
f = input('Enter the frequency (Hz): ');
P = input('Enter the 3-phase load power at the receiving end (MW): ');
pf = input('Enter the power factor of the load: ');
R = input('Enter the per-phase resistance of the line (ohm): ');
X = input('Enter the per-phase reactance of the line (ohm): ');
B = input('Enter the per-phase shunt susceptance of the line (mho or Siemen): ');

% Choosing receiving end as the phasor reference (0 deg)

Vr = 1e3*V; % receiving end line-line voltage in V
Pr = 1e6*P; % 3-phase load power in W
Z = R+X*1i; 
Y = B*1i;

% Phase values:
vr = Vr/sqrt(3);
pr = Pr/3;

% Calculations
ir_mag = pr/(vr*pf);
ir_ang = -acos(pf);
ir = complex(ir_mag*cos(ir_ang),ir_mag*sin(ir_ang));
vc = vr+ir*Z/2;
ic = vc*Y;
is = ic+ir;
vs = vc+is*Z/2; % sending end phase voltage in V
vs_ll = sqrt(3)*abs(vs)/1e3; % sending end line-line voltage in kV
ps = abs(vs*is*cos(angle(vs)-angle(is))); % sending end 1-phase real power in W
ps3ph = 3*ps/1e6; % sending end 3-phase real power in MW
qs = abs(vs*is*sin(angle(vs)-angle(is))); % sending end 1-phase reactive power in VAR
qs3ph = 3*qs/1e6; % sending end 3-phase reactive power in MVAR
pfs = cos(angle(vs)-angle(is)); % sending end power factor
loss = 3*(ps-pr)/1e6; % total 3-phase real power loss in MW
eff = pr/ps*100; % efficiency
VR = (abs(vs)-vr)/abs(vs)*100; % voltage regulation

fprintf('\nFor the given load conditions:\n');
disp('1. Sending end line-line voltage (kV): '); vs_ll
disp('2. Sending end 3-phase real power (MW): '); ps3ph
disp('3. Sending end 3-phase reactive power (MVAR): '); qs3ph
disp('4. Sending end power factor: '); pfs
disp('5. Total 3-phase real power loss in MW: '); loss
disp('6. % Efficiency: '); eff
disp('7. % Voltage Regulation: '); VR

n = 0;

for P = 0:.1:20
n = n+1;
a(n) = P;   
pr = 1e6*P/3;

ir_mag = pr/(vr*pf);
ir_ang = -acos(pf);
ir = complex(ir_mag*cos(ir_ang),ir_mag*sin(ir_ang));
vc = vr+ir*Z/2;
ic = vc*Y;
is = ic+ir;
vs = vc+is*Z/2; % sending end phase voltage in V
vs_ll(n) = sqrt(3)*abs(vs); % sending end line-line voltage in V
ps = abs(vs*is*cos(angle(vs)-angle(is))); % sending end 1-phase real power in W
ps3ph(n) = 3*ps/1e6; % sending end 3-phase real power in MW
qs = abs(vs*is*sin(angle(vs)-angle(is))); % sending end 1-phase reactive power in VAR
qs3ph(n) = 3*qs/1e6; % sending end 3-phase reactive power in MVAR
pfs = cos(angle(vs)-angle(is)); % sending end power factor
loss(n) = 3*(ps-pr)/1e6; % total 3-phase real power loss in MW
eff(n) = pr/ps*100; % efficiency
VR(n) = (abs(vs)-vr)/abs(vs)*100; % voltage regulation

end

subplot(3,2,1);
plot(a,vs_ll); grid on; xlabel('Load Power (MW) ---->'); ylabel('Vs (V) ---->'); title('Sending end line-line voltage v/s load');
subplot(3,2,2);
plot(a,ps3ph); grid on; xlabel('Load Power (MW) ---->'); ylabel('Ps (MW) ---->'); title('Sending end 3-phase real power v/s load');
subplot(3,2,3);
plot(a,qs3ph); grid on; xlabel('Load Power (MW) ---->'); ylabel('Qs (MVAR) ---->'); title('Sending end 3-phase reactive power v/s load');
subplot(3,2,4);
plot(a,loss); grid on; xlabel('Load Power (MW) ---->'); ylabel('Loss (MW) ---->'); title('Total 3-phase real power loss v/s load');
subplot(3,2,5);
plot(a,eff); grid on; xlabel('Load Power (MW) ---->'); ylabel('% Efficiency ---->'); title('Efficiency v/s load');
subplot(3,2,6);
plot(a,VR); grid on; xlabel('Load Power (MW) ---->'); ylabel('% VR ---->'); title('Voltage regulation v/s load');
