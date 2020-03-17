function ck= check (a1,b1,num)
    if (a1==1 && b1==1)||(a1==num && b1==num)
        ck=-1;
    elseif (a1==num || b1==num)||(a1==1 || b1==1)
        ck=0;
    else 
    ck=1;
    end
end
function yj=yuejie(a1,b1,num)
    if(a1<1||a1>num)
        yj=1;
    end
    if(b1<1||b1>num)
        yj=1;
    end
    yj=1;
end
num=input('please input N');
a=zeros(num);
crrt=zeros(num,1);
biao=[1 0;0 1;0 -1;-1 0];
for i 1:num
    for j 1:num
        if check(i,j,num)==-1
            a(i,j)=2;
        elseif check(i,j,num)==0
            a(i,j)=3;
        else
            a(i,j)=4;
        end
        for k 1:4
            if yuejie(i+biao(1,k),j+biao(2,k),num)
                a(i+biao(1,k),j+biao(2,k))=1;
            end
        end
    end
end
a=inv(a);
crrt(1)=5;
kk=crrt*a;
            