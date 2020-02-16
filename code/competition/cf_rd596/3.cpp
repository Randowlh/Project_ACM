#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n, k, d;
    cin >> n >> k >> d;
    int mi = inf;
    map<int, int> s;
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int cnt = 0;
    for (int i = 0; i < d; i++)
    {
        if (s.count(v[i]) == 0)
        {
            cnt++;
            s[v[i]] = 1;
        }
        else
            s[v[i]]++;
    }
    mi = min(mi, cnt);
    for (int i = d; i < n; i++)
    {
        s[v[i - d]]--;
        if (s[v[i - d]] == 0)
            cnt--;
        if (s[v[i]] == 0)
            cnt++;
        s[v[i]]++;
        mi = min(mi, cnt);
    }
    cout << mi << endl;
}
int main()
{
    // std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}