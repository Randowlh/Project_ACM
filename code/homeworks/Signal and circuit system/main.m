num=input('please input N   ');
a=zeros(num*num);
crrt=zeros((num*num),1);
for i= 1:num*num
    for j= i:num*num
        if(i==j)
            if check(i,num)==-1
                a(i,j)=2;
            elseif check(i,num)==0
                a(i,j)=3;
            else
                a(i,j)=4;
            end
        elseif yuejie(i,j,num)==1
                a(i,j)=-1;
                a(j,i)=-1;
        end
    end
end
a1=inv(a);
crrt(1)=1;
crrt(num)=-1;
kk=a1*crrt;
an =zeros(num);
add=-kk(num);
for i=0:num-1
    for j=1:num
        an(i+1,j)=kk(i*num+j)+add;
    end
end
surf(an(1:num,1:num));

            