#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
#define int long long
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
inline void out(int a)
{
    if (a)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
struct node
{
    string name;
    double score;
    int age;
    bool operator<(node a)
    {
        if (score == a.score)
        {
            if (age == a.age)
            {
                return name < a.name;
            }
            else
                return age < a.age;
        }
        else
            return score > a.score;
    }
    node(string n, int a, double s) : name(n), age(a), score(s) {}
};
void work()
{
    vector<node> v;
    int n;
    while (cin >> n)
    {
        v.clear();
        int age;
        double score;
        string tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp >> age >> score;
            node a(tmp, age, score);
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            cout << v[i].name << ' ' << v[i].age << ' ';
            printf("%.2lf\n", v[i].score);
        }
    }
}
signed main()
{
    //freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}