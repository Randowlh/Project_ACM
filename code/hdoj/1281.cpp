#include<bits/stdc++.h>
using namespace std;
const int inf =0x7FFFFFFF;
typedef long long ll;
int mp[150][150];
int pr[150];
int book[150];
int n, m, k;
int ans = 0;
int tmp = 0;
int cnt = 0;
vector<int> s, e;
bool dfs(int x)
{
    for (int i = 1; i <= m;i++){
        if(!book[i]&&mp[x][i]){
            book[i] = 1;
            if(pr[i]==-1||dfs(pr[i])){
                pr[i] = x;
                return true;
            }
        }
    }
    return false;
}
void xyl(){
    tmp = 0;
    memset(pr, -1, sizeof(pr));
    for (int i = 1; i <= m;i++){
        memset(book, 0, sizeof(book));
        if(dfs(i)){
            tmp++;
        }
    }
    return;
}
void work()
{
    
   while( cin >> n >> m >> k){
    cnt++;
    int u, w;
    s.clear();
    e.clear();
    ans = 0;
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < k; i++)
    {
        cin >> u >> w;
        mp[u][w] = 1;
        s.push_back(u);
        e.push_back(w);
    }
    xyl();
    int ipt = 0;
    ans = tmp;
    for (int i = 0;i<s.size(); i++){
        mp[s[i]][e[i]] = 0;
        xyl();
        if(ans>tmp){
            ipt++;
        }
        mp[s[i]][e[i]] = 1;
    }
    cout << "Board "<<cnt<<" have "<<ipt<<" important blanks for "<<ans<<" chessmen." << endl;
   }
    return;
}
int main(){
   // freopen("in.txt","r",stdin);
    int t=1;
   // cin>>t;
    while(t--){
        work();
    }
    return 0;
}