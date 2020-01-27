#include <bits/stdc++.h>
using namespace std;
const int inf = 10000000;
typedef long long ll;
int mp[100][100];
int n,c,r;
int cnt;
map<string,int> M;
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (mp[i][j] > mp[i][k] + mp[k][j])
                    mp[i][j] = mp[i][k] + mp[k][j];
}
int fenpei(string k){
    if(M.count(k)==0){
        M[k]=cnt;
        cnt++;
        return cnt-1;
    }else 
    return M[k];
}
void work()
{
    int k=0;
    while(cin>>n>>c>>r){
        M.clear();
        cnt=2;
        k++;
        
        if(n==0&&c==0&&r==0){
            break;
        }
        cout<<k<<'.'<<' ';
        for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++){
            mp[i][j]=inf;
        }
        for(int i=0;i<=n;i++)
            mp[i][i]=0;
        string tmp;
        int start=1;
        cin>>tmp;
        M[tmp]=1;
        vector<int> e;
        for(int i=0;i<c;i++){
            cin>>tmp;
            e.push_back(fenpei(tmp));
        }
        char backw,forw,t;
        int v;
        string tmp2;
        for(int i=0;i<r;i++){
            cin>>tmp;
            cin>>backw>>t>>v>>t>>forw;
            cin>>tmp2;
            int w=fenpei(tmp);
            int u=fenpei(tmp2);
            if(backw=='<'){
                mp[u][w]=min(mp[u][w],v);
            }
            if(forw=='>'){
                mp[w][u]=min(mp[w][u],v);
            }
        }
        floyd();
        ll ans=0;
        for(int i=0;i<c;i++){
            ans+=mp[start][e[i]];
            ans+=mp[e[i]][start];
        }
        cout<<ans<<endl;
    }
    return ;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}