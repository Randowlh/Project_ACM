#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N=3e3+10;
int n,m;
int a[N],dp[N],s[N];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    int T;
    //freopen("in.txt","r",stdin);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for (int i=n;i>=1;i--)s[i]=s[i+1]+a[i];
    int ans=0;
    for (int k=0;k<=n;k++){
        if (s[k+1]>m)continue;
        int r=m-s[k+1];
        for (int i=1;i<=r;i++)dp[i]=0;
        dp[0]=1;
        for (int i=1;i<k;i++){
            for (int j=r;j>=a[i];j--){
                dp[j]+=dp[j-a[i]];
            }
        }
        for (int i=r;i>r-a[k];i--){
            ans+=dp[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}