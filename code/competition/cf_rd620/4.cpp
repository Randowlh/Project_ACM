#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    cin >> n;
    string tmp;
    cin >> tmp;
    vector<int> l;
    int u = 1;
    int cnt = 1;
    l.push_back(-1);
    for (int i = 0; i < n - 1; i++)
    {
        if (tmp[i] == '<')
        {
            l.push_back(u);
            u++;
        }
        else
        {
            cnt++;
            l.push_back(-1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        //  cout << l[i] << 's' << endl;
    }
    u = cnt;
    for (int i = 0; i < n; i++)
    {
        if (l[i] != -1)
        {
            l[i] += cnt;
        }
        else
        {
            l[i] = u;
            u--;
        }
    }
    tmp.push_back('<');
    vector<int> s;
    u = n;
    int pr = -1;
    cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (tmp[i] == '<')
        {
            if (pr == -1)
            {
                pr = i;
            }
        }
        else
        {
            if (pr != -1)
            {
                for (int j = i - pr; j >= 0; j--)
                {
                    s.push_back(u - j);
                }
                u -= i - pr + 1;
            }
            s.push_back(u);
            u--;
            pr = -1;
        }
    }
    if (pr != -1)
    {
        for (int j = n - 1 - pr; j >= 0; j--)
        {
            s.push_back(u - j);
        }
    }
    if (s[n - 1] == 0)
    {
        for (int i = 0; i < n - 1; i++)
        {
            s[i]--;
        }
        s[n - 1] = n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << ' ';
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << l[i] << ' ';
    }
    cout << endl;
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //  freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}