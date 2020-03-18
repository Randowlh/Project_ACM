function ck= check (a1,b1,num)
    if (a1<num || b1<num)||(a1>=num*(num-1) || b1>=num*(num-1))
        ck=0;
    else 
    ck=1;
    end
end