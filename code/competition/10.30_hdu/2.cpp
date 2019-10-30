#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long date[100010];
int find(int s,int e,int t){
    if(s==e){
        return s;
    }if(s+1==e){
        if(t<date[e])
        return s;
        else return e;
    }
        else{
            if(date[(s+e)/2]>=t){
                return find(s,(s+e)/2,t);
            }else
            {
                return find((s+e)/2+1,e,t);
            }
    }
}
int main(){
 int n,m;
 long long tmp;
 int t;
    scanf("%d",&t);
    for(int q=0;q<t;q++){
        scanf("%d",&n);
        if(n>0){
            scanf("%lld",&date[0]);
        }
        for(int i=1;i<n;i++){
           scanf("%lld",&date[i]);
           date[i]+=date[i-1]; 
        }
        long long tmp;
        for(int i=0;i<m;i++){
            scanf("%lld",&tmp);
           int ans=find(0,n-1,tmp);
           printf("%dlol\n",ans);
        }
    }
    return 0;
}