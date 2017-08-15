function [avg,dev]=avdv(a)
avg=sum(a)/length(a);
dev=std(a);
end
