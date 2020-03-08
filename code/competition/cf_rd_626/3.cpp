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
    int num = 0;
    int cnt = 0;
    int t = 0;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            if (num == 0)
            {
                if (tmp[i] == '(')
                    cnt++;
                else
                {
                    num++;
                    a = i;
                }
            }
            else
            {
                if (tmp[i] == ')')
                {
                    num++;
                }
                else
                {
                    num--;
                    if (num == 0)
                    {
                        b = i;
                        t += (b - a + 1);
                    }
                }
            }
        }
        else
        {
            if (tmp[i] == '(')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
    }
    if (cnt != 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << t << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}