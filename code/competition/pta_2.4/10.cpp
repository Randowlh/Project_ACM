#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{
    int x;
    int t;
};

int n;
int vic[100010];
int book[100010];
vector<int> v[100010];
void work()
{
    cin >> n;
    int tmp;
    int k;
    for (int i = 1; i <= n; i++)
    {   
        cin>>k;
        for(int j=0;j<k;j++){
        scanf("%d", &tmp);
        book[tmp] = 1;
        v[i].push_back(tmp);
        }
    }
    int s;
    for (int i = 1; i <= n; i++)
    {
        if (book[i] == 0)
        {
            s = i;
            break;
        }
    }
    queue<node> q;
    node x;
    x.x = s;
    x.t = 1;
    vic[s] = 1;
    q.push(x);
    while (!q.empty())
    {
        for (int i = 0; i < v[q.front().x].size(); i++)
        {
            if(vic[v[q.front().x][i]]==0){
                vic[v[q.front().x][i]]=q.front().t+1;
                node x;
                x.x=v[q.front().x][i];
                x.t=q.front().t+1;
                q.push(x);
            }
        }
        q.pop();
    }
    int mx=-1;
    int mix=-1;
    for(int i=1;i<=n;i++){
        if(mx<vic[i]){
            mx=vic[i];
            mix=i;
        }
    }
    cout<<mix<<endl;
}
int main()
{
  //  freopen("in.txt", "r", stdin);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}