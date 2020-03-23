#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    map<int, vector<int>> M;
    set<int> s;
    s.clear();
    M.clear();
    cin >> n;
    int k;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
        cin >> k;
        int tmp;
        for (int j = 1; j <= k; j++)
        {
            cin >> tmp;
            M[i].push_back(tmp);
        }
    }
    set<int> dsm;
    for (int i = 1; i <= n; i++)
    {
        int f = 0;
        for (int j = 0; j < M[i].size(); j++)
        {
            if (s.count(M[i][j]) != 0)
            {
                s.erase(M[i][j]);
                f = 1;
                break;
            }
        }
        if (!f)
        {
            dsm.insert(i);
        }
    }
    if (dsm.empty())
    {
        cout << "OPTIMAL" << endl;
    }
    else
    {
        cout << "IMPROVE" << endl;
        cout << *dsm.begin() << ' ' << *s.begin() << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}