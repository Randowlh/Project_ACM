#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
struct trie
{
    int next[500000][26], cnt;
    bool flag[500000];
    ll rt[500000];
    void clear()
    {
        for (int i = 0; i <= cnt; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                next[i][j] = 0;
            }
            flag[i] = 0;
            rt[i]=0;
        }
        cnt = 0;
        return;
    }
    void insert(string a, int q)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            rt[p] += q;
            int c = a[i] - 'a';
            if (next[p][c] == 0)
            {
                next[p][c] = ++cnt;
            }
            p = next[p][c];
        }
        rt[p] += q;
        flag[p] = 1;
    }
    int find(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - 'a';
            if (next[p][c] == 0)
            {
                return false;
            }
            p = next[p][c];
        }
        return flag[p];
    }
    ll tj(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - 'a';
            if (next[p][c] == 0)
            {
                return 0;
            }
            p = next[p][c];
        }
        return rt[p];
    }
} node;
string biao[12] = {{"\0"}, {"\0"}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};
string t;
string ans;
string k;
int ct = 0;
int cnt = 0;
int mx = 0;
void dfs(int step)
{
    if (step == k.size())
    {
        if (node.tj(t) > mx)
        {
            mx = node.tj(t);
            ans = t;
        }
        return;
    }
    if (node.tj(t) <= mx)
    {
        return;
    }
    //cout<<step<<"sada"<<endl;
    for (int i = 0; i < biao[k[step] - '0'].size(); i++)
    {
        t.push_back(biao[k[step] - '0'][i]);
        dfs(step + 1);
        t.pop_back();
    }
    return;
}
void work()
{
    map<string, string> s;
    node.clear();
    int n;
    scanf("%d", &n);
    string tmp;
    int v;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp >> v;
        node.insert(tmp, v);
    }
    int m;
    scanf("%d", &m);
    cnt++;
    printf("Scenario #%d:\n", cnt);
    for (int j = 0; j < m; j++)
    {
        cin >> tmp;
        int fl=0;
        tmp.pop_back();
        for (int i = 0; i < tmp.size(); i++)
        {   
            if(tmp[i]=='1'||fl==1){
               // cout<<endl;
                fl=1;
                continue;
            }
            //continue;
            t.clear();
            mx = 0;
            ans.clear();
            if (s.count(tmp.substr(0, i+1)) != 0)
            {  
                cout<<s[tmp.substr(0, i+1)]<<endl;
            }
            else
            {
                k = tmp.substr(0, i+1);
                dfs(0);
                if (mx == 0)
                {
                    cout << "MANUALLY\n";
                    s[tmp.substr(0, i+1)] = "MANUALLY";
                }
                else
                {
                    cout<<ans<<endl;
                    s[tmp.substr(0, i+1)] = ans;
                }
            }
        }
          //  if(cnt!=ct||j!=m-1)
            printf("\n");
    }
    //if(cnt!=ct)
    printf("\n");
    
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    ct = t;
    while (t--)
    {
        work();
    }
    return 0;
}