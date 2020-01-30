#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
/*
struct trie
{
    int next[500000][26], cnt;
    bool flag[500000];
    //ll rt[500000];
    void clear()
    {
        for (int i = 0; i <= cnt; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                next[i][j] = 0;
            }
            flag[i] = 0;
        //    rt[i]=0;
        }
        cnt = 0;
        return;
    }
    void insert(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
         //   rt[p] += q;
            int c = a[i] - 'a';
            if (next[p][c] == 0)
            {
                next[p][c] = ++cnt;
            }
            p = next[p][c];
        }
       // rt[p] += q;
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
    int check(string k){
        int p = 0;
        for (int i = 0; i < k.size(); i++)
        {
            int c = k[i] - 'a';
            if (next[p][c] == 0)
            {
                return false;
            }
            p = next[p][c];
        }
        int fl=0;
        if(flag[p]){
            return true;
        }
        for(int i=0;i<26;i++){
            if(next[p][i]!=0)
            return true;
        }
        return false;
    }
} node;
*/
struct node
{
    int v;
    char a;
};
void work(){
    string s;
    string t;
    cin>>s>>t;
    set<char> a;
    for(int i=0;i<s.size();i++)
    a.insert(s[i]);
    for(int i=0;i<t.size();i++){
        if(a.count(t[i])==0){
             cout<<-1<<endl;
        return;
        }
    }
    vector<node> k;
    char tmp=0;
    for(int i=0;i<s.size();i++){
        if(tmp!=s[i]){
            node x;
            tmp=s[i];
            x.a=s[i];
            x.v=1;
            k.push_back(x);
        }else{
            k[k.size()-1].v++;
        }
    }  
    int cnt=0;
    for(int i=0;i<t.size();){
        cnt++;
        int now=i;
        for(int j=0;j<k.size();j++){
            int tmp=k[j].v;
            while(k[j].a==t[now]){
                tmp--;
                now++;
                if(tmp<=0)
                break;
            }
        }
        i=now;
    }
    cout<<cnt<<endl;
    return;
}
int main(){
    freopen("in.txt","r",stdin);
    int t=1;
    cin>>t;
    while(t--){
        work();
    }
    return 0;
}