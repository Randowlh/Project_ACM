#include <bits/stdc++.h>
using namespace std;
const int inf = 100000000;
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
        cout<<k<<'.'<<' ';
        if(n==0&&c==0&&r==0){
            break;
        }
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
        }
    }
    return 0;
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