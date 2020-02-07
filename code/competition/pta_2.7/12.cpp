#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
vector<int> h;
void work()
{
    int n, m;
    int t;
    cin >> n >> m;
    h.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        h.push_back(t);
        int now = i;
        while (now > 1)
        {
            if (h[now] > h[now / 2])
                break;
            swap(h[now], h[now / 2]);
            now /= 2;
        }
    }
    string tmp;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a;
        // cout<<a<<endl;
        cin >> tmp;
        if (tmp == "is")
        {
            cin >> tmp;
            if (tmp == "the")
            {
                cin >> tmp;
                if (tmp == "root")
                {
                    if (h[1] == a)
                    {
                        cout << "T" << endl;
                    }
                    else
                        cout << "F" << endl;
                    continue;
                }
                else
                {
                    cin >> tmp;
                    int b;
                    cin >> b;
                    int mix = 0;
                    for (int i = 1; i <= n; i++)
                    {
                        if (a == h[i])
                        {
                            mix = i;
                            break;
                        }
                    }
                    if ((mix * 2 + 1 <= n && h[mix * 2 + 1] == b) || (mix * 2 <= n && h[mix * 2] == b))
                    {
                        cout << "T" << endl;
                    }
                    else
                    {
                        cout << "F" << endl;
                    }
                    continue;
                }
            }
            else
            {
                cin >> tmp;
                cin >> tmp;
                int b;
                cin >> b;
                int mix = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (b == h[i])
                    {
                        mix = i;
                        break;
                    }
                }
                if ((mix * 2 + 1 <= n && h[mix * 2 + 1] == a) || (mix * 2 <= n && h[mix * 2] == a))
                {
                    cout << "T" << endl;
                }
                else
                {
                    cout << "F" << endl;
                }
                continue;
            }
        }
        else
        {
            cin >> b;
            cin >> tmp;
            cin >> tmp;
            cin >> tmp;
            cin >> tmp;
            int posa = 0, posb = 0;
            int fl = 0;
            for (int i = 1; i <= n; i++)
            {
                if (h[i] == a)
                {
                    posa = i;
                }
                if (h[i] == b)
                    posb = i;
                if (posa && posb)
                    break;
            }
            if (posa / 2 == posb / 2)
                cout << "T" << endl;
            else
                cout << "F" << endl;
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}