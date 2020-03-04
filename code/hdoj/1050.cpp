#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    vector<pair<int, int>> date;
    int flag[210];
    memset(flag, 1, sizeof(flag));
    for (int i = 0; i < n; i++)
    {
        pair<int, int> a;
        cin >> a.first >> a.second;
        if (a.first & 1)
            a.first++;
        if (a.second & 1)
            a.second++;
        if (a.first > a.second)
            swap(a.first, a.second);
        date.push_back(a);
    }
    sort(date.begin(), date.end());
    int cnt = 0;
    while (true)
    {
        cnt++;
        int f = 0;
        int jie = -1;
        for (int i = 0; i < n; i++)
        {
            if (flag[i] && jie < date[i].first)
            {
                flag[i] = 0;
                f = 1;
                jie = date[i].second;
            }
        }
        if (!f)
            break;
    }
    cnt--;
    cout << cnt * 10 << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}