#include <bits/stdc++.h>
using namespace std;
struct node
{
    int lab;
    int cap;
    double x, y, z;
};
int n, t;
int now, nowr;
vector<node> st, rsv;
inline bool cmp(int i, int j)
{
    node b = rsv[i];
    node c = rsv[j];
    node a = st[now];
    double ans1 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
    double ans2 = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y) + (a.z - c.z) * (a.z - c.z);
    if (ans1 == ans2)
        return a.cap > b.cap;
    else
        return ans1 < ans2;
}
inline bool cmp2(int i, int j)
{
    node b = st[i];
    node c = st[j];
    node a = rsv[nowr];
    double ans1 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z);
    double ans2 = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y) + (a.z - c.z) * (a.z - c.z);
    if (ans1 == ans2)
        return a.cap > b.cap;
    else
        return ans1 < ans2;
}
int lg[300];
int mp[300][300];
void prsolve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[i][j] = j;
        }
        now = i;
        sort(mp[i], mp[i] + n, cmp);
    }
    return;
}
void ChoosePartener()
{
    memset(lg, -1, sizeof(lg));
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        int f = 0;
        int t = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (lg[mp[t][i]] == -1)
            {
                lg[mp[t][i]] = t;
                f = 1;
                break;
            }
            else
            {
                nowr = mp[t][i];
                if (cmp2(t, lg[mp[t][i]]))
                {
                    q.push(lg[mp[t][i]]);
                    lg[mp[t][i]] = t;
                    f = 1;
                    break;
                }
            }
        }
        if (!f)
        {
            cout << "Impossible" << endl;
            cout << endl;
            break;
        }
    }
    return;
}
int main()
{
    //  freopen("in.txt", "r", stdin);
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        st.clear();
        rsv.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            node x;
            cin >> x.lab >> x.cap >> x.x >> x.y >> x.z;
            st.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            node x;
            cin >> x.lab >> x.cap >> x.x >> x.y >> x.z;
            rsv.push_back(x);
        }
        prsolve();
        ChoosePartener();
        for (int i = 0; i < n; i++)
        {
            cout << lg[i] + 1 << " " << i + 1 << endl;
        }
    }
    return 0;
}