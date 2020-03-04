#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
void work()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        vector<int> self;
        vector<int> cp;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            self.push_back(tmp);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            cp.push_back(tmp);
        }
        sort(cp.begin(), cp.end(), greater<int>());
        sort(self.begin(), self.end(), greater<int>());
        int tail = n - 1;
        int tailn = n - 1;
        int head = 0;
        int cnt = 0;
        for (int i = 0; i <= tailn; i++)
        {
            if (self[head] > cp[i])
            {
                cnt++;
                head++;
                continue;
            }
            else if (self[head] == cp[i])
            {
                while (self[tail] > cp[tailn])
                {
                    cnt++;
                    tail--;
                    tailn--;
                }
                if (self[tail] < cp[i])
                    cnt--;
                tail--;
                continue;
            }
            else
            {
                tail--;
                cnt--;
                continue;
            }
        }
        cout << cnt * 200 << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}