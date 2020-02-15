#include <bits/stdc++.h>
using namespace std;
struct node
{
    vector<int> a;
};
class mx
{
public:
    int size;
    vector<node> date;
    void make(int x)
    {
        size = x;
        date.resize(x);
        for (int i = 0; i < x; i++)
        {
            date[i].a.resize(x);
        }
        int step = 0;
        int k = x / 2;
        int cnt = 1;
        while (step < k)
        {

            for (int i = step; i < x - step - 1; i++)
            {
                date[i].a[step] = cnt;
                cnt++;
            }
            for (int i = step; i < x - step - 1; i++)
            {
                date[x - step - 1].a[i] = cnt;
                cnt++;
            }
            for (int i = x - step - 1; i > step; i--)
            {
                date[i].a[x - step - 1] = cnt;
                cnt++;
            }
            for (int i = x - step - 1; i > step; i--)
            {
                date[step].a[i] = cnt;
                cnt++;
            }
            step++;
        }
        if (x % 2 == 1)
        {
            date[x / 2].a[x / 2] = cnt;
        }
    }
};
ostream &operator<<(ostream &os, const mx &a)
{
    for (int i = 0; i < a.size; i++)
    {
        for (int j = 0; j < a.size; j++)
        {
            os << setw(4) << a.date[i].a[j];
        }
        os << endl;
    }
    return os;
}
int main()
{
    int n;
    cin >> n;
    mx tmp;
    tmp.make(n);
    cout << tmp;
    return 0;
}