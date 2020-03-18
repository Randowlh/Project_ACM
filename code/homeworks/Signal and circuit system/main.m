num=input('please input N   ');
a=zeros(num*num-2);
crrt=zeros((num*num)-2,1);
for i= 1:num*num-2
    for j= i:num*num-2
        if(i==j)
            if check(i,j,num)==-1
                a(i,j)=2;
            elseif check(i,j,num)==0
                a(i,j)=3;
            else
                a(i,j)=4;
            end
        end
        if yuejie(i,j,num)==1
                a(i,j)=-1;
                a(j,i)=-1;
        end
    end
end
a1=inv(a);
crrt(1)=5;
crrt(num)=5;
crrt((num*num)-2)=0;
crrt(num*(num-1)-1)=0;
kk=a1*crrt;
an =zeros(num);
an(1,1)=5;
an(num,num)=0;
for i=2:num
    an(1,i)=kk(i-1);
end
for i=1:num-1
    for j=1:num
        if(i*num+j~=num*num)
        an(i+1,j)=kk(i*num+j-1);
        end
    end
end
an(num,num)=0;
surf(an(1:num,1:num));

            