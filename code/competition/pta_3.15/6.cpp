#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int arr[1000000];
void work()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> v;
    int tmp;
    int ji = 0;
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &tmp);
        if (tmp & 1)
            ji++;
        v.push_back(tmp);
    }
    if (k == 1 || n > 100000)
    {
        cout << ji - k << endl;
        return;
    }
    int ans = inf;
    ll sum = 0;
    for (int i = n - k; i < n; i++)
    {
        sum += v[i];
    }
    for (int q = sum & 1; q <= k; q += 2)
    {
        int tmpp = q;
        for (int i = 0; i < n; i++)
        {
            arr[i] = 0;
        }
        vector<int> tt;
        tt.clear();
        for (int i = 0; i < k - q; i++)
        {
            tt.push_back(0);
        }
        for (int i = 0; i < q; i++)
        {
            tt.push_back(1);
        }
        do
        {
            tmpp = q;
            for (int i = n - k; i < n; i++)
            {
                arr[i] = tt[i - n + k];
            }
            for (int i = n - k - 1; i >= 0; i--)
            {
                if ((v[i + k] + arr[i + k]) % 2 != v[i] % 2)
                {
                    arr[i] = 1;
                    tmpp++;
                }
                else
                    arr[i] = 0;
            }
            ans = min(ans, tmpp);
        } while (next_permutation(tt.begin(), tt.end()));
    }
    printf("%d\n", ans);
}
int main()
{
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}