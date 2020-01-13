#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
ll ans = (ll)inf*100000000;
vector<ll> arr;
void dfs(ll a,ll b,int n){
    if(n==arr.size()){
        ans=min(ans,max(a,b));
        return ;
    }
    dfs(a*arr[n],b,n+1);
    dfs(a,b*arr[n],n+1);
    return ;
}
void work()
{
    ll x;
    cin >> x;
    ll tmp = x;
    for (ll i = 2; i*i<=tmp; i++)
    {
        if (tmp % i == 0)
        {
            ll k=1;
            while(tmp%i==0){
                k*=i;
                tmp/=i;
            }
            arr.push_back(k);
        }
    }
    if(tmp>1){
        arr.push_back(tmp);
    }
    dfs(1,1,0);
    cout<<ans<<' '<<x/ans<<endl;
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}