#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
struct node
{
    int a, b, c, pt, num;
    bool operator<(node a) const
    {
        return this->c < a.c;
    }
} date[5010];
int dp[5010];
int bl[5010];
int book[5010];
int n, m, k;
priority_queue<node> qe;
int main()
{   
    freopen("d.txt","r",stdin);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &date[i].a, &date[i].b, &date[i].c);
        date[i].pt = -1;
        date[i].num = i;
    }
    int u, v;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        date[u].pt = v;
    }
    dp[n + 1] = 0;
    int mx = 0;
    int mn = 0;
    int now = k;
    //int now = k;
    for (int i = 1; i <= n; i++)
    {
        if (now < date[i].a)
        {
            cout << -1 << endl;
            return 0;
        }
        bl[i] = now;
        now += date[i].b;
    }
    for (int i = n; i >= 0; i--)
    {
        dp[i] = max(date[i + 1].a, dp[i + 1] - date[i + 1].b); //cerr<<i<<' '<<dp[i]<<endl;
    }
    int cur=k;
    for(int i=0;i<=n;i++){
        cur+=date[i].b;
        bl[i]=cur-dp[i];
        cur=dp[i];
    }
    for(int i=0;i<=n;i++){
        dp[i]=bl[i];
    }
    /////////////////////////
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<endl;
    }
    ll ans = 0;
    //cout<<"YEs"<<endl;
    for (int i = n; i >= 1; i--)
    {
        qe.push(date[i]);
        if (dp[i] > 0)
        {
            if (date[i].pt != -1 && book[i] == 0)
            {
                while (dp[i] > 0 && !qe.empty() && book[date[i].pt] == 0)
                {
                    if (qe.top().c <= date[date[i].pt].c)
                    {
                        ans += date[date[i].pt].c;
                        book[date[i].pt] = 1;
                        break;
                    }
                    else
                    {
                        ans += qe.top().c;
                        book[qe.top().num] = 1;
                        qe.pop();
                        dp[i]--;
                    }
                }
                while (dp[i] > 0 && !qe.empty())
                {
                    ans += qe.top().c;
                    book[qe.top().num] = 1;
                    qe.pop();
                    dp[i]--;
                }
            }
            else
            {
                while (dp[i] > 0 && !qe.empty())
                {
                    ans += qe.top().c;
                    book[qe.top().num] = 1;
                    qe.pop();
                    dp[i]--;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}