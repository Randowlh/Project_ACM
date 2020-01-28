#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct trie
{
    int next[500000][11], cnt;
    bool fl[500000];
    void clear()
    {
        for (int i = 0; i <= cnt; i++)
        {
            for (int j = 0; j < 10; j++)
                next[i][j] = 0;
            fl[i] = 0;
        }
        cnt = 0;
        return;
    }
    void insert(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            // tol[p]++;
            int c = a[i] - '0';
            if (next[p][c] == 0)
            {
                next[p][c] = ++cnt;
            }
            p = next[p][c];
        }
        // tol[p]++;
        fl[p] = true;
    }
    bool find(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - '0';
            if (next[p][c] == 0)
                return false;
            p = next[p][c];
        }
        return fl[p];
    }
    bool check(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - '0';
            if (next[p][c] == 0)
                return false;
            if(fl[p]==true)
            return false;
            p = next[p][c];
        }
        return true;
    }
} node;
vector<string> ans;
void work()
{
    node.clear();
    ans.clear();
    int n;
    cin >> n;
    string tmp;
    for (int i=0;i<n;i++){
        cin>>tmp;
        ans.push_back(tmp);
        node.insert(tmp);
    }
    int fl=1;
    for(int i=0;i<n;i++){
        if(!node.check(ans[i])){
            fl=0;
            break;
        }
    }
    if(fl==1){
        cout<<"YES"<<endl;
    }else
    cout<<"NO"<<endl;
    return;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}