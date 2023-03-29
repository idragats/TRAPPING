clc;clear;clf;
x=importdata('trapping.txt');
x1=importdata('distribution.txt')';
times=linspace(0,length(x1),length(x1));
figure(1)
histogram(x)
xlabel("TRAPPING TIME")
ylabel("PARTICLES AT SAME TRAPPING TIME")
title("TRAPPING TIME DISTRIBUTION C=0.01")

y(1)=x1(1);
for i=2:length(x1)
    y(i)=y(i-1)+x1(i);
    
end

for i=1:length(y)
    y(i)=(length(x)- y(i))/length(x);
end



figure(2)
plot(times,y)
hold on
fplot(@(N) (1-10^-3)^((pi*N)/(log(N))))
legend('Distribution','WRITE EQUATION')
xlabel("TRAPPING TIME")
ylabel("SURVIVAL PROBABILITY")
title("SURVIVAL DISTRIBUTION C=0.01")

