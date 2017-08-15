clear all;
close all;
clc;
n=input('Choose: \n1. delta-wye \n2. wye-delta \n');
if n==1
    d=input('Enter the value of R1, R2, R3 of Delta connected circuit :\n');
    s=sum(d);
    w(1,1)=d(1,1)*d(1,3)/s;
    w(1,2)=d(1,1)*d(1,2)/s;
    w(1,3)=d(1,2)*d(1,3)/s;
    disp('The Ra, Rb, Rc of Wye connected circuit are :');
    disp(w);
elseif n==2
    w=input('Enter the value of Ra, Rb, Rc of Wye connected circuit :\n');
    s=w(1,1)*w(1,2)+w(1,2)*w(1,3)+w(1,1)*w(1,3);
    d(1,1)=s/w(1,3);
    d(1,2)=s/w(1,1);
    d(1,3)=s/w(1,2);
    disp('The R1, R2, R3 of Delta connected circuit are :');
    disp(d);
end
