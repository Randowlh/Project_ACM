void SA(){
    double now=ans;
    double temp=stemp;
    while(temp>1e-14){
        double tnow=now+((rand()<<1)-RAND_MAX)*temp;
        if(tnow<l||tnow>r){
            temp*=delta;
            continue;
        }
        double new_ans=calc(tnow);
        double de=new_ans-mx;
        if(de>0){
            now=tnow;
            ans=tnow;
            mx=new_ans;
        }else if(exp(-de/temp)*RAND_MAX>rand()){
            now=tnow;
        }
        temp*=delta;
    }
}
void repeat(double t){
    while((double)clock()/CLOCKS_PER_SEC<t){
        SA();
    }
}