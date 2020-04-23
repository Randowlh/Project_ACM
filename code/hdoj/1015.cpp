#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> now;
string ans;
int book[1010];
int n;
string tmp;
inline int pows(int x, int a)
{
    int ans = 1;
    for (int i = 0; i < x; i++)
    {
        ans *= a;
    }
    return ans;
}
void dfs(int step)
{
    if (step == 5)
    {
        if (n == (now[0] - pows(2, now[1]) + pows(3, now[2]) - pows(4, now[3]) + pows(5, now[4])))
        {
            string t;
            for (int i = 0; i < now.size(); i++)
            {
                t.push_back((char)(now[i] + 'A' - 1));
            }
            if (ans.empty())
                ans = t;
            else
                ans = max(ans, t);
        }
        return;
    }
    for (int i = 0; i < tmp.size(); i++)
    {
        if (!book[i])
        {
            book[i] = 1;
            now.push_back((int)tmp[i] - 'A' + 1);
            dfs(step + 1);
            now.pop_back();
            book[i] = 0;
        }
    }
    return;
}
signed main()
{
    //freopen("in.txt", "r", stdin);
    while (cin >> n >> tmp)
    {
        memset(book, 0, sizeof(book));
        ans.clear();
        if (n == 0 && tmp == "END")
            break;
        for (int i = 0; i < tmp.size(); i++)
        {
            now.push_back(tmp[i] - 'A' + 1);
            book[i] = 1;
            dfs(1);
            now.pop_back();
            book[i] = 0;
        }
        if (ans.empty())
            cout << "no solution" << endl;
        else
            cout << ans << endl;
    }
}