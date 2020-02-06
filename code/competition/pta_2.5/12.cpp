#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
double mp[1010][1010];
int j[1010];
void work()
{
    int n, m;
    cin >> n >> m;
    for (int q = 0; q < m; q++)
    {
        int k;
        cin >> k;
        string t;
        int tmp;
        vector<int> mem;
        for (int i = 0; i < k; i++)
        {   
            cin>>t;
            int fl=1;
            if(t[0]=='-')
            fl=2;
            stringstream ss(t);
            ss>>tmp;
            tmp = abs(tmp);
            j[tmp]=fl;
            mem.push_back(tmp);
        }
        double plus = 1.0 / k;
        for (int i = 0; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                mp[mem[i]][mem[j]] += plus;
                mp[mem[j]][mem[i]] += plus;
            }
        }
    }
  // cout<<j[0]<<"asda"<<endl;
    int a, b;
    cin >> a >> b;
    int ta, tb;
    ta = a;
    tb = b;
    a = abs(a);
    b = abs(b);
    double bas = mp[a][b];
    double nowa = -1;
    double nowb = -1;
    vector<int> ansb;
    vector<int> ansa;
    for (int i = 0; i < n; i++)
    {
        if (j[a] != j[i])
        {
            if (nowa < mp[a][i])
            {
                nowa = mp[a][i];
                ansa.clear();
                ansa.push_back(i);
            }
            else if (nowa == mp[a][i])
            {
                ansa.push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (j[b] != j[i])
        {
            if (nowb < mp[b][i])
            {
                nowb = mp[b][i];
                ansb.clear();
                ansb.push_back(i);
            }
            else if (nowb == mp[b][i])
            {
                ansb.push_back(i);
            }
        }
    }
    if(nowa==nowb&&nowb==bas){
        cout<<ta<<' '<<tb<<endl;
        return;
    }
        for (int i = 0; i < ansa.size(); i++)
        {
            cout << ta << ' ';
            if (j[ansa[i]] == 2)
            {
                cout << '-';
            }
            cout << ansa[i] << endl;
        }
    
        for (int i = 0; i < ansb.size(); i++)
        {
            cout << tb << ' ';
            if (j[ansb[i]] == 2)
            {
                cout << '-';
            }
            cout << ansb[i] << endl;
        }
    
    return;
}
int main()
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