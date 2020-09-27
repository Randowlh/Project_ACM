#include <bits/stdc++.h>
using namespace std;
#define maxn 1100000
struct AC{
    struct node{
        int son[26],flag,fail;
    }trie[maxn];
    int cnt=1;
    void ins(string &a){
        int now=1;
        for(int i=0;i<a.size();i++){
            int v=a[i]-'a';
            if(!trie[now].son[v])
                trie[now].son[v]=++cnt;
            now=trie[now].son[v];
        }
        trie[now].flag++;
    }
    void getfail(){
        queue<int> q;
        for(int i=0;i<26;i++)
            trie[0].son[i]=1;
        q.push(1);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            for(int i=0;i<26;i++){
                int now=trie[t].son[i];
                int fail=trie[t].fail;
                if(!now){
                    trie[t].son[i]=trie[fail].son[i];
                    continue;
                }
                trie[now].fail=trie[fail].son[i];
                q.push(now);
            }
        }
    }
    int query(string &tmp){
        int now=1,ans=0;
        for(int i=0;i<tmp.length();i++){
            int v=tmp[i]-'a';
            int k=trie[now].son[v];
            while(k>1&&trie[k].flag!=-1){
                ans+=trie[k].flag;
                trie[k].flag=-1;
                k=trie[k].fail;
            }
            now=trie[now].son[v];
        }
        return ans;
    }
}tt;
int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string tmp;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        tt.ins(tmp);
    }
    tt.getfail();
    cin>>tmp;
    cout<<tt.query(tmp)<<endl;
}