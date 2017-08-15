function [avg,dev]=avdv2(a)
if nargout==1
    disp('Average Calculator:');
    avg=sum(a)/length(a);
    
elseif nargout==2
    disp('Average and Standard Deviation Calculator:');
    avg=sum(a)/length(a);
    dev=std(a);
else error('Specify whether you need Average or both Avg and Standard Deviation');
end
