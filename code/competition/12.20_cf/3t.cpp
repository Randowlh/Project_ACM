#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt=0;
int a[200005];
void work()
{
    int n;
    scanf("%d",&n);
    int suma=0;
    int sumb=0;
    for(int i=1;i<=2*n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1){
            suma++;
        }else{
            sumb++;
        }
    }
    int tmp=suma-sumb;
    int cnt=0;
   // cout<<tmp<<endl;
    map<int,int>m;
    for(int i=n+1;i<=2*n;i++){
        if(a[i]==1){
            cnt++;
        }else{
            cnt--;
        }
        if(m[cnt]==0){
            m[cnt]=i-n;
        }
        //printf("%d ",cnt);
    }
    int ans=9999999;
    if(tmp==0){
        printf("0\n");return;
    }
    if(m[tmp]){
        ans=m[tmp];
    }
    for(int i=n;i>=1;i--){
        if(a[i]==1){
            tmp--;
        }else{
            tmp++;
        }
        if(tmp==0){
            ans=min(ans,n-i+1);
        }
        if(m[tmp]!=0){
            ans=min(ans,n-i+1+m[tmp]);
        }
    }
    printf("%d\n",ans);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    scanf("%d",&T);
    //cin>>T;
    //T=1;
    for(int i=1;i<=T;i++){
        work();
    }
}