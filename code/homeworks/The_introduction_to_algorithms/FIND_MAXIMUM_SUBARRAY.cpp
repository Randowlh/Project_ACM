#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
vector<int> date;
int find_cross_subarry(int left, int mid, int right)
{
    int left_max = -inf;
    int sum = 0;
    for (int i = mid; i >= left; i--)
    {
        sum += date[i];
        left_max = max(left_max, sum);
    }
    int right_max = -inf;
    sum = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        sum += date[i];
        right_max = max(right_max, sum);
    }
    return max(right_max, max(left_max, left_max + right_max));
}
int find_subarry(int left, int right)
{
    if (left == right)
    {
        return date[left];
    }
    int mid = (left + right) >> 1;
    int ans = find_subarry(left, mid);
    ans = max(ans, find_subarry(mid + 1, right));
    ans = max(ans, find_cross_subarry(left, mid, right));
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        date.push_back(tmp);
    }
    int ans = find_subarry(0, n - 1);
    cout << ans << endl;
    return 0;
}