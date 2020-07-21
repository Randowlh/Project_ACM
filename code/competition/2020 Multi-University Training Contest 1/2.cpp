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
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int n, m;
vector<int> mp[100100];
map<int,vector<pair<int,int>>> qr[100100];
map<int, int> fu[100100];
vector<int> xw[100100];
vector<pair<int,int>> vl[100100];
vector<int> aa[100100];
int tails[100100];
void init(int n){
    for (int i = 0; i <= n;i++){
        mp[i].clear();
        qr[i].clear();
        fu[i].clear();
        xw[i].clear();
        vl[i].clear();
        aa[i].clear();
        tails[i] = 0;
    }
}
void work()
{
    n = read(), m = read();
    int tmp;
    init(n);
    for (int i = 1; i <= n; i++)
    {
        tmp = read();
        vl[i].push_back(make_pair(tmp, 0));
        }
    int u, v;
    for (int i = 0; i < m;i++){
        u=read(),v=read();
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
        int q = read();
    int opt,a, b;
    vector<int> as;
    for (int i = 1; i <= q;i++){
        opt = read();
        if(opt^1){
            a = read(), b = read();
            vl[a].push_back(make_pair(b,i));
        }else{
            a = read();
            as.push_back(a);
            xw[a].push_back(i);
        }
    }
    for (int i = 1; i <= n;i++){
        if(xw[i].size()){
            for (int j = 0; j < mp[i].size(); j++){
                fu[j][vl[mp[i][j]][0].first]++;
            }
        }
    }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < mp[i].size(); j++)
            {
                if (!xw[mp[i][j]].size())
                    continue;
                int &tt = mp[i][j];
                for (int k = 0; k < xw[tt].size(); k++)
                {
                    int b = 0;
                    int e = vl[i].size();
                    while (b < e)
                    {
                        int mid = (b + e) >> 1;
                        if (!(vl[i][mid].second <= xw[tt][k]))
                            b = mid + 1;
                        else
                            e = mid;
                }
                qr[tt][xw[tt][k]].push_back(make_pair(i,vl[i][e].second));
            }
        }
    }
    for (int i = 1; i <= n;i++){
        for (int j = 0;j<qr[i].size();j++){
            for (int k = 0;k<qr[i][j].size();k++){
                fu[qr[i][j][k].first]
            }
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int t = 1;
    t = read();
    while (t--)
    {
        work();
    }
    return 0;
}