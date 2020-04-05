#include <bits/stdc++.h>
using namespace std;
class Q
{
private:
    typedef long long ll;
    ll zi;
    ll mu;
    inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
    inline void tf()
    {
        ll t = gcd(zi, mu);
        zi /= t;
        mu /= t;
    }

public:
    Q(ll a = 0, ll b = 0) : zi(a), mu(b) {}
    Q operator+(const Q &a)
    {
        ll tzi = zi * a.mu + a.zi * mu;
        ll tmu = mu * a.mu;
        ll tt = gcd(tzi, tmu);
        tzi /= tt;
        tmu /= tt;
        Q ans(tzi, tmu);
        return ans;
    }
    Q operator-(const Q &a)
    {
        ll tzi = zi * a.mu - a.zi * mu;
        ll tmu = mu * a.mu;
        ll tt = gcd(tzi, tmu);
        tzi /= tt;
        tmu /= tt;
        Q ans(tzi, tmu);
        return ans;
    }
    Q operator/(const Q &a)
    {
        ll tzi = zi * a.mu;
        ll tmu = mu * a.zi;
        ll tt = gcd(tzi, tmu);
        tzi /= tt;
        tmu /= tt;
        Q ans(tzi, tmu);
        return ans;
    }
    Q operator*(const Q &a)
    {
        ll tzi = zi * a.zi;
        ll tmu = mu * a.mu;
        ll tt = gcd(tzi, tmu);
        tzi /= tt;
        tmu /= tt;
        Q ans(tzi, tmu);
        return ans;
    }
    Q &operator=(const Q &a)
    {
        zi = a.zi;
        mu = a.mu;
        return *this;
    }
    friend ostream &operator<<(ostream &os, Q a)
    {
        if (a.zi % a.mu == 0)
        {
            os << a.zi / a.mu;
            return os;
        }

        ll t = a.gcd(a.zi, a.mu);
        a.zi /= t;
        a.mu /= t;
        if (a.mu < 0)
        {
            a.mu = -a.mu;
            a.zi = -a.zi;
        }
        os << a.zi << '/' << a.mu;
        return os;
    }
    friend istream &operator>>(istream &is, Q &a)
    {
        is >> a.zi >> a.mu;
        return is;
    }
};
int main()
{
    Q a, b;
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
    cout << a + b << '\t' << a - b << '\t' << a * b << '\t' << a / b << endl;
    return 0;
}