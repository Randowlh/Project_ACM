#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
int book[20];
int dui[1000];
int dui2[1000];
vector<vector<int>> ans;
vector<int> tmp;
void dfs(int step)
{
    if (step == n + 1)
    {
        if (ans.size() < 3)
        {
            ans.push_back(tmp);
        }
        cnt++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!book[i] && !dui[i - step + 500] && !dui2[i + step])
        {
            dui[i - step + 500] = 1;
            dui2[i + step] = 1;
            book[i] = 1;
            tmp.push_back(i);
            dfs(step + 1);
            tmp.pop_back();
            book[i] = 0;
            dui[i - step + 500] = 0;
            dui2[i + step] = 0;
        }
    }
    return;
}
int main()
{
    cin >> n;
    memset(book, 0, sizeof(book));
    dfs(1);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    cout << cnt << endl;
    return 0;
}