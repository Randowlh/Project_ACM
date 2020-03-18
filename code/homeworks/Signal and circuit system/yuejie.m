function yj=yuejie(a1,b1,num)
    if (a1+num==b1)
        yj=1;
    elseif(mod(a1,num)~=0&&a1+1==b1)
        yj=1;
    else
    yj=0;
    end
end