#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int flag[1000];
    memset(flag, 1, sizeof(flag));
    int cnt = 0;
    ll tol = 0;
    while (cnt < n)
    {
        int ma = 0;
        int mix = 0;
        for (int i = 0; i < n; i++)
        {
            if (flag[i])
            {
                for (int j = 1; j < n; j++)
                {
                    if (flag[(i + j) % n])
                    {
                        if (ma < abs(v[i] - v[(i + j) % n]))
                        {
                            //   cout << "dsa" << endl;
                            ma = abs(v[i] - v[(i + j) % n]);
                            mix = i;
                        }
                    }
                }
            }
        }
        //cout << ma << ' ' << mix << endl;
        tol += ma;
        flag[mix] = 0;
        cnt++;
    }
    cout << tol << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}