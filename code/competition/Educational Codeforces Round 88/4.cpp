#include <bits/stdc++.h>
using namespace std;
int main()
{
    //reopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp;
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int ans = 0;
    for (int i = 1; i <= 30; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += v[j];
            if (v[j] > i)
                sum = 0;
            sum = max(sum, 0);
            ans = max(ans, sum - i);
        }
    }
    cout << ans << endl;
}