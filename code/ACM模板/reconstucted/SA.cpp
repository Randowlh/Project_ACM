double ans=0;
double stemp=1997;
double delta=0.997;
mt19937 rnd(233);
double calc(double x){
}
void SA(){
    double now=ans;
    double temp=stemp;
    while(temp>1e-14){
        double tnow=now+((rnd()<<1)-RAND_MAX)*temp;
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
        }else if(exp(-de/temp)*RAND_MAX>rnd()){
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
