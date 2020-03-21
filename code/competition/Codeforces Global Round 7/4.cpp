#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
inline bool check(string a)
{
    for (int i = 0; i < a.size() / 2; i++)
    {
        if (a[i] != a[a.size() - 1 - i])
        {
            return false;
        }
    }
    return true;
}
void work()
{
    string tmp;
    cin >> tmp;
    int head = 0;
    int tail = tmp.size() - 1;
    for (int i = 0; i < tmp.size() / 2; i++)
    {
        if (tmp[head] == tmp[tail])
        {
            head++;
            tail--;
        }
    }
    if (head >= tail)
    {
        cout << tmp << endl;
        return;
    }
    // cout << head << ' ' << tail << endl;
    int forh = 0;
    int afth = 0;
    for (int i = head; i < tail; i++)
    {
        if (check(tmp.substr(head, i - head + 1)))
        {
            forh = i;
        }
    }
    for (int i = tail; i > head; i--)
    {
        if (check(tmp.substr(i, tail - i + 1)))
        {
            afth = i;
        }
    }
    if (forh - head < tail - afth)
    {
        cout << tmp.substr(0, head) << tmp.substr(afth, 999999999) << endl;
    }
    else
    {
        cout << tmp.substr(0, forh + 1) << tmp.substr(tail + 1, 99999999) << endl;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}