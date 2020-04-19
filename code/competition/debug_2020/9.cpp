#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
#define bug cout << "here\n"
typedef long long ll;
#define int long long
const int mod = (0 ? 1000000007 : 998244353);
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
class bignum
{
public:
    typedef long long ll;
    char *head;
    int lim;
    int size;

public:
    bignum &operator+(const bignum &a)
    {
        static bignum ans;
        int fl = 0;
        if (max(a.size, size) + 2 >= max(a.lim, lim))
            fl = 3;
        ans.head = new char[max(a.lim, lim) + fl];
        ans.lim = max(a.lim, lim) + fl;
        ans.head[0] = 0;
        for (int i = 0; i < max(a.size, size); i++)
        {
            if (i < min(a.size, size))
            {
                ans.head[i + 1] = (ans.head[i] + a.head[i] + head[i]) / 10;
                ans.head[i] = (ans.head[i] + a.head[i] + head[i]) % 10;
            }
            else if (a.size > size)
            {
                ans.head[i + 1] = (ans.head[i] + a.head[i]) / 10;
                ans.head[i] = (ans.head[i] + a.head[i]) % 10;
            }
            else
            {
                ans.head[i + 1] = (ans.head[i] + head[i]) / 10;
                ans.head[i] = (ans.head[i] + head[i]) % 10;
            }
        }
        if (ans.head[max(a.size, size)] == 0)
            ans.size = max(a.size, size);
        else
            ans.size = max(a.size, size) + 1;
        return ans;
    }
    bignum &operator-(const bignum &a)
    {
        static bignum ans;
        ans.head = new char[max(a.lim, lim)];
        ans.lim = max(a.lim, lim);
        ans.head[0] = 0;
        for (int i = 0; i < max(a.size, size); i++)
        {
            if (i < min(a.size, size))
            {
                if (ans.head[i] + head[i] - a.head[i] < 0)
                {
                    ans.head[i + 1] = -1;
                    ans.head[i] += 10;
                }
                else
                    ans.head[i + 1] = 0;
                ans.head[i] = ans.head[i] + head[i] - a.head[i];
            }
            else
            {
                if (ans.head[i] + head[i] < 0)
                {
                    ans.head[i + 1] = -1;
                    ans.head[i] += 10;
                }
                ans.head[i] = ans.head[i] + head[i];
            }
        }
        ans.size = 1;
        for (int i = max(size, a.size) - 1; i > 0; i--)
        {
            if (ans.head[i] != 0)
            {
                ans.size = i + 1;
                break;
            }
        }
        return ans;
    }
    ~bignum() { delete[] head; }
    bignum(ll a = 0)
    {
        lim = 100;
        head = new char[100];
        size = 0;
        while (a != 0)
        {
            head[size++] = a % 10;
            a /= 10;
        }
    }
    bignum(bignum const &a)
    {
        head = new char[a.lim];
        lim = a.lim;
        size = a.size;
        for (int i = 0; i < a.size; ++i)
            head[i] = a.head[i];
    }
    bignum(bignum &&a)
    {
        head = a.head;
        a.head = nullptr;
        lim = a.lim;
        size = a.size;
    }
    friend ostream &operator<<(ostream &out, bignum &a)
    {
        for (int i = a.size - 1; i >= 0; i--)
        {
            out << (int)a.head[i];
        }
        return out;
    }
    friend istream &operator>>(istream &in, bignum &a)
    {
        string ii;
        in >> ii;
        a.lim = ii.size() + 10;
        a.head = new char[a.lim];
        a.size = ii.size();
        for (int i = ii.size() - 1; i >= 0; i--)
        {
            a.head[ii.size() - i - 1] = ii[i] - '0';
        }
        return in;
    }
} tmp, a(1);
void work()
{
    cin >> tmp;
    tmp + 1;
    if ((tmp + a).size > 20)
    {
        cout << "Zhang San will never have girlfriend!" << endl;
    }
    else
        cout << (tmp + a) << endl;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        work();
    }
    return 0;
}