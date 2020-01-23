#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod =10000;
struct node
{
    int date[3][3];
    node operator*(node a)const{
        node x;
        x.date[1][1]=(date[1][1]*a.date[1][1]+date[1][2]*a.date[2][1])%mod;
        x.date[1][2]=(date[1][1]*a.date[1][2]+date[1][2]*a.date[2][2])%mod;
        x.date[2][1]=(date[2][1]*a.date[1][1]+date[2][2]*a.date[2][1])%mod;
        x.date[2][2]=(date[2][1]*a.date[1][2]+date[2][2]*a.date[2][2])%mod;
        return x;
    }
    node operator=(node a){
        date[1][1]=a.date[1][1];
        date[1][2]=a.date[1][2];
        date[2][1]=a.date[2][1];
        date[2][2]=a.date[2][2];
        return *this;
    }
    node operator*=(node a){
        *this= *this*a;
        return *this;
    }
}cst,e;
node powerpow(node x ,int n){
    node ans=e;
    node k=x;
    ll tmp=1;
    while(n>=tmp){
        ans=ans*x;
        n-=tmp;
        tmp*=2;
        x=x*x;
    }
    if(n!=0){
        ans=ans*powerpow(cst,n);
    }
    return ans;
}
int main(){
    e.date[1][1]=1;  
    e.date[1][2]=0;
    e.date[2][1]=0;
    e.date[2][2]=1;
    cst.date[1][1]=1;
    cst.date[1][2]=1;
    cst.date[2][1]=1;
    cst.date[2][2]=0;
    ll n;
    while(cin>>n){
        if(n==-1)
        break;
        cout<<powerpow(cst,n).date[1][2]<<endl;
    }
    return 0;
}