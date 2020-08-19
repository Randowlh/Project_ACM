#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int ans[1100000],ansma[1100000];
int date[1100000];
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
int main(){
    //freopen("in.txt", "r", stdin);
    int n,k;
    //scanf("%d%d",&n,&k);
    rd(n),rd(k);
    int tmp;
    for(int i=1;i<=n;i++)
        rd(date[i]);
    for(int i=1;i<=n;i++){
        if(i>k)
            s.erase(s.find(date[i-k]));
        s.insert(date[i]);
        if(i>=k){
            ans[i-k+1]=*s.begin();
            ansma[i-k+1]=*s.rbegin();
        }
    }
    for(int i=1;i<=n-k+1;i++)
        printf("%d ",ans[i]);
    printf("\n");
    for(int i=1;i<=n-k+1;i++)
        printf("%d ",ansma[i]);
    printf("\n");
}