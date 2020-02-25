#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
struct node
{
    int l;
    int r;
};
void work()
{
    int n, m;
    cin >> n >> m;
    int tmp;
    int arr[100000];
    vector<int> v2;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        v2.push_back(tmp);
    }
    sort(v2.begin(), v2.end());
    int l = v2[0];
    int r = v2[0] + 1;
    vector<node> v;
    for (int i = 1; i < v2.size(); i++)
    {
        if (v2[i] == r)
        {
            r++;
        }
        else
        {
            node x;
            x.l = l;
            x.r = r;
            if (x.r <= n)
                v.push_back(x);
            l = v2[i];
            r = l + 1;
        }
    }
    node x;
    x.l = l;
    x.r = r;
    if (x.r <= n)
        v.push_back(x);
    for (int i = 0; i < v.size(); i++)
    {
        //cout << "dasds" << endl;
        // cout << v[i].l << ' ' << v[i].r << endl;
        sort(arr + v[i].l, arr + v[i].r + 1);
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << arr[i] << ' ';
    // }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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