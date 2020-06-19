#include <bits/stdc++.h>
using namespace std;
const int ut = -522432511;
struct node
{
    int v, l, r;
    void init()
    {
        v = ut, l = ut, r = ut;
    }
    bool operator==(node a)
    {
        if (v == a.v && l == a.l && r == a.r)
            return true;
        return false;
    }
};
vector<node> date[2], datet;
int main()
{
    int n;
    while (cin >> n)
    {
        date.clear();
        datet.clear();
        string tt;
        cin >> tt;
        vector<int> v;
        for (int i = 0; i < tt.size(); i++)
        {
        }
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            int now = 0;
            if (date.empty())
            {
                node a;
                a.init();
                a.v = tmp;
                date.push_back(a);
                continue;
            }
            while (true)
            {
                if (tmp < date[now].v)
                {
                    if (date[now].l == ut)
                    {
                        node a;
                        a.init();
                        a.v = tmp;
                        date.push_back(a);
                        date[now].l = date.size() - 1;
                        break;
                    }
                    now = date[now].l;
                    continue;
                }
                else
                {
                    if (date[now].r == ut)
                    {
                        node a;
                        a.init();
                        a.v = tmp;
                        date.push_back(a);
                        date[now].r = date.size() - 1;
                        break;
                    }
                    now = date[now].r;
                    continue;
                }
            }
        }
    }
}
