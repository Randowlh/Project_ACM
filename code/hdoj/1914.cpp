#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int n;
int cnt;
vector<char> boy, girl;
map<char, vector<char>> M;
map<char, char> lg, lp;
bool cmp(char a, char b, char c)
{
    for (int i = 0; i < n; i++)
    {
        if (M[a][i] == b)
        {
            return true;
        }
        if (M[a][i] == c)
        {
            return false;
        }
    }
    return false;
}
void work()
{
    lp.clear();
    lg.clear();
    M.clear();
    boy.clear();
    girl.clear();
    cin >> n;
    char t;
    queue<char> q;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        q.push(t);
        boy.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        girl.push_back(t);
    }
    for (int i = 0; i < n; i++)
    {
        char k;
        char tmp;
        cin >> k;
        cin >> tmp;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            M[k].push_back(tmp);
        }
    }
    for (int i = 0; i < n; i++)
    {
        char k;
        char tmp;
        cin >> k;
        cin >> tmp;
        for (int j = 0; j < n; j++)
        {
            cin >> tmp;
            M[k].push_back(tmp);
        }
    }
    while (!q.empty())
    {
        char t = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (lg.count(M[t][i]) == 0)
            {
                lp[t] = M[t][i];
                lg[M[t][i]] = t;
                break;
            }
            else if (cmp(M[t][i], t, lg[M[t][i]]))
            {
                q.push(lg[M[t][i]]);
                lg[M[t][i]] = t;
                lp[t] = M[t][i];
                break;
            }
        }
    }
    sort(boy.begin(), boy.end());
    for (int i = 0; i < n; i++)
    {
        cout << boy[i] << ' ' << lp[boy[i]] << endl;
    }
    if (cnt > 0)
        cout << endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    cin >> cnt;
    while (cnt--)
    {
        work();
    }
    return 0;
}