#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
void work()
{
    vector<int> ans;
    ans.clear();
    int n, s;
    cin >> n >> s;
    int q1, q0;
    q1 = 0;
    q0 = 0;
    char c;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c == '0')
            q0++;
        else
            q1++;
        ans.push_back(q0 - q1);
    }
    int tmp;
    tmp = q0 - q1;
    int a = 0;
    int fl = 0;
    //cout<<"tmp="<<tmp<<endl;
    if (tmp != 0)
        for (int i = 0; i < ans.size(); i++)
        {
            if ((s - ans[i]) % tmp == 0 && (s - ans[i]) / tmp >= 0)
            {
                a++;
                //fl=1;
            }
        }
    else
        for (int i = 0; i < ans.size(); i++)
        {
            if ((s - ans[i]) == 0)
            {
                fl = 1;
                //fl=1;
            }
        }
    if (tmp == 0)
    {
        if (fl == 1){
            cout << -1 << endl;
            return;
        }
        else
        {
            if (s == 0)
                cout << 1 << endl;
            else
                cout << 0 << endl;
                return;
        }
    }
    else
    {
        if (s == 0)
            a++;
        cout << a << endl;
        return;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}