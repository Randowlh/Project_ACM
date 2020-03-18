function ck= check (a1,num)
    if(a1==1||a1==num*num||a1==num||a1==(num-1)*num+1)
        ck=-1;
    elseif (a1<=num ||a1>num*(num-1)|| mod(a1,num)==0||mod(a1,num)==1)
        ck=0;
    else 
    ck=1;
    end
end