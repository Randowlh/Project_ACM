#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{
    string now;
    string next;
    int date;
    /* data */
};
map<string, node> M;
void work()
{
    string s;
    int n;
    cin >> s >> n;
    string now;
    string next;
    int date;
    for (int i = 0; i < n; i++)
    {
        cin >> now;
        cin >> date;
        cin >> next;
        node x;
        x.date = date;
        x.next = next;
        x.now = now;
        M[now] = x;
    }
    vector<node> v;
    while (true)
    {
        if (s == "-1")
        {
            break;
        }
        v.push_back(M[s]);
        s = M[s].next;
    }
    int fl = 0;
    int fr = 0;
    int ed = v.size() - 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (fl % 2 == 0)
        {
            cout << v[ed].now << ' ' << v[ed].date << ' ';
            if (ed == fr)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << v[fr].now << endl;
            }
            ed--;
        }
        else
        {
            cout << v[fr].now << ' ' << v[fr].date << ' ';
            if (ed == fr)
            {
                cout << -1 << endl;
            }
            else
            {
                cout << v[ed].now << endl;
            }
            fr++;
        }
        fl++;
    }
    return;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //   freopen("in.txt","r",stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}