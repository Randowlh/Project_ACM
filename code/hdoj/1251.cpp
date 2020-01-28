#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct trie
{
    int next[500000][26], cnt;
    bool fl[500000];
    ll tol[500000];
    void clear()
    {   
        for(int i=0;i<=cnt;i++){
            next[i][0]=0;
            next[i][1]=0;
            fl[i]=0;
            tol[i]=0;
        }
        cnt=0;
        return;
    }
    void insert(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {   
            tol[p]++;
            int c = a[i] - 'a';
            if (next[p][c] == 0)
            {
                next[p][c] = ++cnt;
            }
            p = next[p][c];
        }
        tol[p]++;
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
            p = next[p][c];
        }
        return (next[p][0] == 0 && next[p][1] == 0);
    }
    ll tj(string a){
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - 'a';
            if (next[p][c] == 0)
                return false;
            p = next[p][c];
        }
        return tol[p];
    }
} node;
int main(){
    freopen("in.txt","r",stdin);
    string tmp;
    int fl=0;
    while(getline(cin,tmp)){
        if(tmp.empty()){
            fl=1;
            continue;
        }
        if(fl==0){
            node.insert(tmp);
        }else{
            cout<<node.tj(tmp)<<endl;
        }
    }
    return 0;
}