#include <bits/stdc++.h>
using namespace std;
vector<int> v;
inline int mins(int a, int b, int c, int d)
{
    return min(a, min(b, min(c, d)));
}
int main()
{
    //  freopen("in.txt", "r", stdin);
    v.push_back(1);
    v.push_back(1);
    int tail2 = 1, tail3 = 1, tail5 = 1, tail7 = 1;
    while (v.size() <= 5852)
    {
        int mi = mins(v[tail2] * 2, v[tail3] * 3, v[tail5] * 5, v[tail7] * 7);
        v.push_back(mi);
        if (v[tail2] * 2 == mi)
            tail2++;
        if (v[tail3] * 3 == mi)
            tail3++;
        if (v[tail5] * 5 == mi)
            tail5++;
        if (v[tail7] * 7 == mi)
            tail7++;
    }
    int n;
    while (cin >> n, n)
    {
        cout << "The " << n;
        if (n % 10 == 1 && n % 100 != 11)
            cout << "st";
        else if (n % 10 == 2 && n % 100 != 12)
            cout << "nd";
        else if (n % 10 == 3 && n % 100 != 13)
            cout << "rd";
        else
            cout << "th";
        cout << " humble number is " << v[n] << "." << endl;
        ;
    }
    return 0;
}