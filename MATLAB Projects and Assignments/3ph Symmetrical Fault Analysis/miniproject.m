% -----------------------------------------------------%
% Power System Simulation Laboratory  --  Mini-project %
% -----------------------------------------------------%
% Sambhav R Jain    107108103                          %
% Yash Prakash      107108095                          %
% Sandeep Rao       107108105                          %
% -----------------------------------------------------%

clc;
clear all;
close all;

fprintf('3-phase symmetrical fault analysis\n\n');
N = input('Enter the number of buses in the existing power system (excluding reference bus): ');

fprintf('\nAssume\n1. Reference bus is denoted by "0"\n2. If there is no impedance between two buses, enter NaN\n\n');

% Formulation of Zbus, by forming Ybus followed by inversion
disp('Enter the physical impedances between buses:');
for m = 1:1:N    
    % Case 1: Impedance between two buses
    for n = m+1:1:N
        % These are the physical impedances between buses, and not the Zbus
        % elements
        z(m,n) = input(sprintf('Enter the z(%d,%d) (e.g. 2j): ',m,n)); 
        % Check if two buses are not at all connected (infinite impedance) 
        % i.e. NaN - Not a Number
        if isnan(z(m,n))
            % If yes, then the admittance would be zero 
            y(m,n) = 0;         
        else
            y(m,n) = 1/z(m,n);
        end
        y(n,m)=y(m,n);
    end
    
    % Case 2: Impedance between a bus and the reference bus
    z(m,m) = input(sprintf('Enter the z(%d,0) (e.g. 2j): ',m));  
    if isnan(z(m,m))
            y(m,m) = 0;
        else
            y(m,m) = 1/z(m,m);
    end    
end

rowsum = sum(y,2); 
for m = 1:1:N
    for n = 1:1:N
        if m == n
            % Diagonal elements of Ybus (Ymm) = sum of all admittances connected
            % to the mth bus
            Y(m,n) = rowsum(m);
        else
            % Off diagonal elements of Ybus (Ymn) = negative of the admittance  
            % connected between m and n            
            Y(m,n) = -y(m,n);
        end                
    end
end

Z = inv(Y);
fprintf('\nThe Zbus of the given power system is:\n');
disp(Z);

% Finding which buses are generator buses and which are load buses
for m = 1:1:N
    g(m) = input(sprintf('\nFor bus %d:\n 1 -> Generator bus\n 2 -> Load bus\nChoose: ',m));
end

while 1
k = input(sprintf('\nEnter the bus index at which a 3-phase fault is to be simulated: '));
if k >=1 && k <= N
    break
else
    fprintf('\nError!! Please enter a value between 1 and %d!\n',N);
end
end

Zf = input(sprintf('\nEnter the fault impedance (zero in case of bolted fault): '));

V = ones(N,1);          % Pre-fault voltages are assumed to be 1 p.u.
I = zeros(N,1); 

I_f = 1/(Z(k,k)+Zf);    % Fault current at bus 'k'
fprintf('\nPer-unit fault current out of bus %d:\n',k);
disp(I_f);
I(k,1) = -I_f;
del_V = Z*I;            % Difference in voltage vector
Vf = V + del_V;         % During-fault voltage vector at buses

fprintf('During-fault voltages (p.u.):\n');
for m = 1:1:N
    fprintf('Vf_%d = ',m);
    disp(Vf(m));
end

fprintf('During-fault currents (p.u.):\n');
for m = 1:1:N
    for n = m+1:1:N
        if isnan(z(m,n))
        If(m,n) = 0;
        else
        If(m,n) = (Vf(m,1)-Vf(n,1))/z(m,n);
        end 
        fprintf('If_%d%d = ',m,n);
        disp(If(m,n));       
    end         
end
% Fault current from generator terminals
for m = 1:1:N
    if g(m) == 1
        If(m,m) = (1-Vf(m,1))/z(m,m);
        fprintf('If_g%d = ',m);
        disp(If(m,m)); 
    end
end

% fprintf('During-fault reactive power flows (p.u.):\n');
% for m = 1:1:N
%     for n = m+1:1:N
%         if isnan(z(m,n))
%         Q(m,n) = 0;
%         Q(n,m) = 0;
%         else
%         Q(m,n) = imag(Vf(m,1)*conj(If(m,n)));
%         Q(n,m) = imag(Vf(n,1)*conj(-If(m,n)));
%         end 
%         fprintf('Q%d%d = ',m,n);
%         disp(Q(m,n)-Q(n,m));       
%     end         
% end