#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int n;
vector<pair<int,int>> v;
int usd[210];
int mx[210];
set<int> s;
void dfs(){
    queue<int> q;
    q.push(1);
    //cout << 1 << endl;
    s.insert(1);
    while(!q.empty()){
        int t=q.front();
        q.pop();
        cout << t << endl;
        for (int i = 0;i<v.size();i++){
            if(t%v[i].first==0&&s.count(t/v[i].first)==0){
                    q.push(t/v[i].first);
                    s.insert(t / v[i].first);
                    break;
            }
            if(t%mx[i]!=0&&s.count(t*v[i].first)==0){
                    q.push(t*v[i].first);
                    s.insert(t * v[i].first);
                    break;
            }
        }
    }
}
void work()
{
    cin >> n;
    pair<int, int> t;
    int tol = 1;
    for (int i = 0; i < n;i++){
        cin>>t.first>>t.second; 
        v.push_back(t);
        tol*=t.second;
    }
    for (int i = 0;i<v.size();i++){
        int nowa = 1;
        for (int j = 0; j < v[i].second;j++){
            nowa*=v[i].first;
        }
        mx[i] = nowa;
    }
            dfs();
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}