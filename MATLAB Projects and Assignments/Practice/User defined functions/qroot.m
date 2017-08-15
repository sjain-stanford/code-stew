function out=qroot()
a=input('Enter the value of a ');
b=input('Enter the value of b ');
c=input('Enter the value of c ');
x1=-b/(2*a);
x2=sqrt(b^2-(4*a*c))/(2*a);
out(1)=x1-x2;
out(2)=x1+x2;
disp('Value of 1st root is :');
disp(out(1));
disp('Value of 1st root is :');
disp(out(2));
end
