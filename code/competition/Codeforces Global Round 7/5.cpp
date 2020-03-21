#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug puts("here\n")
typedef long long ll;
int head, tail;
string tmp;
int KmpSearch(char *s, char *p)
{
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    while (i < sLen && j < pLen)
    {
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
        if (j == -1 || s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
            //next[j]即为j所对应的next值
            j = next[j];
        }
    }
    if (j == pLen)
        return i - j;
    else
        return -1;
}
inline bool
check(int s, int tp)
{
    if (tp == 1)
    {
        for (int i = 2; (s + i) <= tail && (s - i) >= head; i++)
        {
            if (tmp[s + i] != tmp[s - i])
            {
                return false;
            }
        }
    }
    return true;
}
void work()
{

    cin >> tmp;
    head = 0;
    tail = tmp.size() - 1;
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
    vector<pair<int, int>> pit;
    pair<int, int> x;
    for (int i = head; i <= tail; i++)
    {
        if (i + 2 <= tail && tmp[i + 2] == tmp[i])
        {
            x.first = i + 1;
            x.second = 1;
            pit.push_back(x);
        }
        else if (i + 1 <= tail && tmp[i + 1] == tmp[i])
        {
            x.first = i;
            x.second = 2;
            pit.push_back(x);
        }
    }
    int s = 0;
    int ma = -1;
    for (int i = 0; i < pit.size(); i++)
    {
        if (pit[i].second == 1)
        {
            if (min(head - pit[i].first, tail - pit[i].first) > ma)
            {
                ma = min(head - pit[i].first, tail - pit[i].first);
                s = pit[i].first;
            }
        }
        else
        {
            if (min(head - pit[i].first, tail - pit[i].first - 1) > ma)
            {
                ma = min(head - pit[i].first, tail - pit[i].first);
                s = pit[i].first;
            }
        }
    }
    for (int i = 0; s + i <= tail && s - i >= head; i++)
    {
        if (check(pi))
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