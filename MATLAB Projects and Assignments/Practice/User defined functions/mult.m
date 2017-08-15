function out=mult(a,b)
%this is a user defined function to multiply two numbers
if (size(a,2)~=size(b,1))
    error('Dimensions rule invalid');
end
out=a*b;
end


