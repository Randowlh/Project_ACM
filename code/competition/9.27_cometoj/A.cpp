#include<cstdio>
#include<iostream>
using namespace std;
const long long md =1000000007;
long long calc(long long x){
    if(x<3){
        return 1;
    }else
    if(x==0){
        return 2;
    }else{
        long long ans=1;
        long long k=x/3;
        int  r =  x%3;
        if(r==0){
            for(long long i=0;i<k;i++){
                ans=ans*3%md;
            }
            return ans;
        }else if(r==1){
            for(long long i=0;i<k-1;i++){
                ans=ans*3%md;
            }
            return ans*4%md;
        }else if(r==2){
            for(long long i=0;i<k;i++){
                ans=ans*3%md;
            }
            return ans*2%md;
        }
    }
}
int main(){
    long long n;
    cin>>n;
    cout<<calc(n)<<endl;
    return 0;
}