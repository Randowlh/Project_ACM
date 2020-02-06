#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
char mp[300][300];
vector<int> tmp, ans;
int book[300];
int n;
int fl = 0;
void dfs(int step, int now)
{
    if (step == n )
    {
         if (mp[tmp[tmp.size() - 1]][tmp[0]] == 'W'){
        ans = tmp;
        fl = 1;
         }
        return;
    }
    if (fl)
        return;

    for (int i = 1; i <= n; i++)
    {
        if (book[i] == 0 && mp[now][i] == 'W')
        {
            // cout<<now<<"->"<<i<<endl;
            book[i] = 1;
            if (fl)
                break;
            tmp.push_back(i);
            dfs(step + 1, i);   
            tmp.pop_back();
            book[i] = 0;
        }
    }
    return;
}
void work()
{
    //int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(fl)
        break;
        book[i] = 1;
        tmp.push_back(i);
        dfs(1, i);
        tmp.pop_back();
        book[i] = 0;
    }
    if (fl == 0)
        cout << "No Solution" << endl;
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << ans[n - 1] << endl;
    }
    return;
}
int main()
{
  //  freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
        //cout<<"No Solution"<<endl;
    }
    return 0;
}