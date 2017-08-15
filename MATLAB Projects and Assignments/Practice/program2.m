clear all;
close all;
clc;
x=input('Enter the values of x: ');
sum=0;
e=2.718;
l=length(x);
for y=1:l
    for n=1:l
        sum=sum+(x(1,n)*e^(-j*y));
    end
    z(1,y)=sum;
    sum=0;
end
disp(z);
disp(abs(z));





    

    
