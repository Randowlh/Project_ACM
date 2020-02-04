#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
struct node
{
    string s;
    string m;
    string f;
    char j;
};
map<string, int> M;
vector<node> date;
bool check(int a, int b, int step)
{
    // cout<<"TES"<<endl;
    if (a == b)
        return false;
    if (step >= 5)
    {
        return true;
    }
    if (date[a].f == date[b].f && date[a].f != "-1")
    {
        return false;
    }
    if (date[a].m == date[b].m && date[a].m != "-1")
    {
        return false;
    }
    if (date[a].f == date[b].m && date[a].f != "-1")
    {
        return false;
    }
    if (date[a].m == date[b].f && date[a].m != "-1")
    {
        return false;
    }
    //cout<<"dsad"<<endl;
    if (M.count(date[a].f) != 0 && M.count(date[b].f) != 0 && check(M[date[a].f], M[date[b].f], step + 1) == false)
    {
        return false;
    }
    if (M.count(date[a].m) != 0 && M.count(date[b].f) != 0 && check(M[date[a].m], M[date[b].f], step + 1) == false)
    {
        return false;
    }
    if (M.count(date[a].m) != 0 && M.count(date[b].m) != 0 && check(M[date[a].m], M[date[b].m], step + 1) == false)
    {
        return false;
    }
    if (M.count(date[a].f) != 0 && M.count(date[b].m) != 0 && check(M[date[a].f], M[date[b].m], step + 1) == false)
    {
        return false;
    }
    return true;
}
void work()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, m, f;
        char j;
        cin >> s >> j >> f >> m;
        node x;
        x.s = s;
        x.j = j;
        x.f = f;
        x.m = m;
        M[s] = date.size();
        date.push_back(x);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    { //  M.erase("-1");
        string a, b;
        cin >> a >> b;
        if (date[M[a]].j == date[M[b]].j)
        {
            cout << "Never Mind" << endl;
            continue;
        }
        else if (check(M[a], M[b], 1))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}
int main()
{
  //    freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
/*

Never Mind
Yes
Never Mind
No
Yes
No
Yes
No
No



*/