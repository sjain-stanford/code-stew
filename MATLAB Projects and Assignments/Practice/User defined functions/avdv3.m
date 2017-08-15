% To find the average and standard deviation of any no of vector inputs
function [avg,dev]=avdv4(varargin)
a=zeros(1,nargin);   % This is preallocation to increase speed
k=1;
for i=1:nargin
    b=cell2mat(varargin(i));
    if length(b)>1
        for j=1:length(b)
            a(k)=b(j);
            k=k+1;
        end
    else a(k)=b;
        k=k+1;
    end
    
end
if nargout==1
    disp('Average Calculator:');
    avg=sum(a)/length(a);
    
elseif nargout==2
    disp('Average and Standard Deviation Calculator:');
    avg=sum(a)/length(a);
    dev=std(a);
else error('Specify whether you need Average or both Avg and Standard Deviation');
end
