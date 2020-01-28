#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct trie
{
    int next[500000][27], cnt;
    bool fl[500000];
    void clear()
    {
        for (int i = 0; i <= cnt; i++)
        {
            for (int j = 0; j < 27; j++)
                next[i][j] = 0;
            fl[i] = 0;
        }
        cnt = 0;
        return;
    }
    bool find(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - 'a';
            if (next[p][c] == 0)
                return false;
            p = next[p][c];
        }
        return fl[p];
    }
    void insert(string a)
    {
        bool flag = false;
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            // tol[p]++;
            int c = a[i] - 'a';
            if (next[p][c] == 0)
            {
                next[p][c] = ++cnt;
            }
            p = next[p][c];
        }
        // tol[p]++;
        fl[p] = true;
    }
    bool check(string a)
    {
        for (int i = 1; i < a.size() - 1; i++)
        {
            if(this->find(a.substr(0,i))&&this->find(a.substr(i,99999999))){
                return true;
            }
        }
        return false;
    }
} node;
vector<string> ans;
int main()
{
    freopen("in.txt", "r", stdin);
    string tmp;
    while (cin >> tmp)
    {
        ans.push_back(tmp);
        node.insert(tmp);
    }
    //  cout<<'?'<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if (node.check(ans[i]))
        {
            cout << ans[i] << endl;
        }
    }
}