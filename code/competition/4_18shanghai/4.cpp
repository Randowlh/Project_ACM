#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
struct date
{
    int mo;
    int dt;
    date(int a = 1, int b = 1) : mo(a), dt(b) {}
    bool operator<(date a)
    {
        if (mo == a.mo)
            return dt < a.dt;
        return mo < a.mo;
    }
};
string ri[] = {"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th", "12th", "13th", "14th", "15th", "16th", "17th", "18th", "19th", "20th", "21st", "22nd", "23rd", "24th", "25th", "26th", "27th", "28th", "29th", "30th", "31st", "32nd"};
void output(int year, int month, int day)
{
    if (month == 5)
        cout << "Mother's Day: May ";
    else
        cout << "Father's Day: June ";
    cout << ri[day - 1] << ", ";
    cout << year << endl;
}
bool run(int year)
{
    if (year % 100 == 0 && year % 400 != 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}
int biao[2][13] = {{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
map<int, vector<date>> M;
void work()
{
    int mm = 0;
    int ff = 0;
    int week = 5;
    int y = 2000, d = 1, m = 1;
    int weekcnt = 0;
    while (y != 2101)
    {
        int f = 1;
        if (run(y))
            f = 0;
        if (d > biao[f][m])
        {
            d = 1;
            m++;
            weekcnt = 0;
        }
        if (m > 12)
        {
            m = 1;
            y++;
        }
        if (m != 6 && m != 5)
        {
            week += biao[f][m];
            week %= 7;
            m++;
            weekcnt = 0;
            if (m > 12)
            {
                m = 1;
                y++;
                mm = 0;
                ff = 0;
            }
            continue;
        }

        if (week == 6)
        {
            weekcnt++;
        }
        if (weekcnt == 2 && m == 5 && mm == 0)
        {
            mm = 1;
            date a;
            a.dt = d;
            a.mo = m;
            M[y].push_back(a);
        }
        if (weekcnt == 3 && m == 6 && ff == 0)
        {
            ff = 1;
            date a;
            a.dt = d;
            a.mo = m;
            M[y].push_back(a);
        }
        week++;
        week %= 7;
        d++;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> y >> m >> d;
        if (date(m, d) < M[y][0])
        {
            output(y, M[y][0].mo, M[y][0].dt);
        }
        else if (date(m, d) < M[y][1])
        {
            output(y, M[y][1].mo, M[y][1].dt);
        }
        else
            output(y + 1, M[y + 1][0].mo, M[y + 1][0].dt);
    }
}
signed main()
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