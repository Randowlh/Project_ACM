#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x7FFFFFFF;
typedef long long ll;
int n;
ll mp[1000][1000];
ll dis[1000];
bool flag[1000];
void work()
{
    int s = 1;
    int e = 2;
    string tmp1,tmp2;
    map<string, int> m;
    cin >> tmp1;
    m[tmp1] = 1;
    cin >> tmp2;
    m[tmp2] = 2;
    int cnt = 3;
    int fl=0;
    if(tmp1==tmp2){
        fl=1;
    }
    vector<ll> b;
    vector<ll> j;
    vector<ll> z;
    //vector<int> s;
    string w, u;
    ll v;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> u >> v;
        if (m.count(w) == 0)
        {
            m[w] = cnt;
            b.push_back(cnt);
            cnt++;
        }
        else
        {
            b.push_back(m[w]);
        }
        if (m.count(u) == 0)
        {
            m[u] = cnt;
            j.push_back(cnt);
            cnt++;
        }
        else
            j.push_back(m[u]);
        z.push_back(v);
    }
    for (int i = 0; i <= cnt; i++)
    {
        for (int j = 0; j <= cnt; j++)
        {
            if (i == j)
            {
                mp[i][j] = 0;
            }
            else
                mp[i][j] = inf;
        }
    }
    
    for (int i = 0; i < b.size(); i++)
    {  // cout<<b[i]<<' '<<j[i]<<' '<<z[i]<<endl;
        mp[b[i]][j[i]] = min(mp[b[i]][j[i]], z[i]);
        mp[j[i]][b[i]] = mp[b[i]][j[i]];
    }
    for (int i = 0; i <= cnt; i++)
    {
        dis[i] = inf;
        flag[i] = true;
    }

    // for (int i = 1; i < cnt; i++)
    // {
    //     for (int j = 1; j < cnt; j++)
    //     {
    //         cout << mp[2][m["supermarket"]] << " ";
    //     }
    //     cout << endl;
    // }
    dis[1] = 0;
    // cout<<m["supermarket"]<<"sadad"<<endl;
    int o = 0;
    while (o < cnt)
    {
        ll mi = inf + 100;
        int mit = 0;
        for (int i = 0; i < cnt; i++)
        {
            if (flag[i] && dis[i] < mi)
            {
                mi = dis[i];
                mit = i;
            }
        }
      //  cout << mit << endl;
        for (int i = 0; i < cnt; i++)
        {
            dis[i] = min(dis[i], dis[mit] + mp[mit][i]);
        }
        flag[mit] = false;
        o++;
    }
    if(fl==1){
        cout<<0<<endl;
    }else
    if (dis[2] == inf)
    {
        cout << -1 << endl;
    }
    else
        cout << dis[2] << endl;
}
int main()
{
    freopen("in.txt", "r", stdin);
    //int t=1;
    //cin>>t;
    while (cin >> n)
    {
        if (n == -1)
            break;
        work();
    }
    return 0;
}