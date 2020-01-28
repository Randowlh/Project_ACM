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
    void insert(string a)
    {
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
    bool check(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - 'a';
            if (next[p][c] == 0)
                return false;
            if(fl[p]==true)
            return false;
            p = next[p][c];
        }
        return true;
    }
} node;
int main(){
    freopen("in.txt","r",stdin);
    string tmp;
    int n;
    while(cin>>n){
        node.clear();
        int mx=0;
        for(int i=0;i<n;i++){
            cin>>tmp;
            mx=max(mx,(int)tmp.size());
            node.insert(tmp);
        }
        cout<<(node.cnt)*2+n-mx<<endl;
    }
    return 0;
}