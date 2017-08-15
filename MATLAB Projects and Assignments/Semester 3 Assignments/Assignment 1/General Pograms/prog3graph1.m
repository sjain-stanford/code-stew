%To plot the graph1
Rl=4:4:40;
for i=1:10
    Il(i)=Vt/(abs(Rt)+Rl(i));
end
plot(Il,Vt);
xlabel('Load current----->');
ylabel('Thevenin Voltage----->');
title('Thevenin Voltage v\s Load current');
