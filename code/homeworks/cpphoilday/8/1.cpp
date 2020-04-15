#include <bits/stdc++.h>
using namespace std;
class bignum
{
private:
    typedef long long ll;
    char *head;
    int lim;
    int size;
    int sign;
    bignum plus(const bignum &a) //无符号加法
    {
        bignum ans;
        int fl = 0;
        if (max(a.size, size) + 2 >= max(a.lim, lim))
            fl = 300;
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
    bignum sub(const bignum &a) //无符号减法
    {
        bignum ans;
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

public:
    bignum operator=(const bignum &a)
    {
        sign = a.sign;
        head = new char[a.lim];
        lim = a.lim;
        size = a.size;
        for (int i = 0; i < a.size; ++i)
            head[i] = a.head[i];
        return *this;
    }
    bignum operator=(bignum &&a)
    {
        sign = a.sign;
        head = a.head;
        a.head = nullptr;
        lim = a.lim;
        size = a.size;
        return *this;
    }
    bool operator<(const bignum &a) //重载小于号，利于后面对减法结果的判断
    {
        if (sign > a.sign)
            return true;
        if (sign < a.sign)
            return false;
        if (sign == 1)
        {
            if (size < a.size)
                return false;
            if (size > a.size)
                return true;
            for (int i = a.size - 1; i >= 0; i--)
            {
                if (head[i] < a.head[i])
                    return false;
                if (head[i] > a.head[i])
                    return true;
            }
            return true;
        }
        if (size < a.size)
            return true;
        if (size > a.size)
            return false;
        for (int i = a.size - 1; i >= 0; i--)
        {
            if (head[i] < a.head[i])
                return true;
            if (head[i] > a.head[i])
                return false;
        }
        return false;
    }
    bignum operator-(const bignum &a) //有符号的减法运算重载
    {
        bignum tt(a);
        bignum ans;
        if (*this < tt) //后一个数比前面的大，结果一定是负的
        {
            if (sign == 1 && tt.sign == 1)
            {
                ans = (*this).sub(tt);
            }
            else if (sign == 1 && tt.sign == 0)
            {
                ans = (*this).plus(tt);
            }
            else
            {
                ans = tt.sub(*this);
            }
            ans.sign = 1;
        }
        else //反之则是正的
        {
            if (sign == 1 && tt.sign == 1)
            {
                ans = tt.sub(*this);
            }
            else if (sign == 0 && tt.sign == 1)
            {
                ans = (*this).plus(tt);
            }
            else
            {
                ans = (*this).sub(tt);
            }
            ans.sign = 0;
        }
        return ans;
    }
    bignum operator+(const bignum &a) //有符号加法
    {
        bignum tt(a);
        bignum ans;
        if (sign == 1 && tt.sign == 1) //两个负数相加，结果为负
        {
            ans = (*this).plus(tt);
            ans.sign = 1;
        }
        else if (sign == 0 && tt.sign == 0) //两个正数相加，结果为正
        {
            ans = (*this).plus(tt);
            ans.sign = 0;
        }
        else if (tt.sign == 1) //后面是负的等价于减法
        {
            tt.sign = 0;
            ans = (*this) - tt;
            tt.sign = 1;
        }
        else //前面的是负的等价于交换再相减
        {
            sign = 0;
            ans = tt - (*this);
            sign = 1;
        }
        return ans;
    }
    ~bignum() { delete[] head; }
    bignum()
    {
        sign = 0;
        lim = 0;
        size = 0;
        head = nullptr;
    }
    bignum(ll a)
    {
        sign = 0;
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
        sign = a.sign;
        head = new char[a.lim];
        lim = a.lim;
        size = a.size;
        for (int i = 0; i < a.size; ++i)
            head[i] = a.head[i];
    }
    bignum(bignum &&a)
    {
        sign = a.sign;
        head = a.head;
        a.head = nullptr;
        lim = a.lim;
        size = a.size;
    }
    friend ostream &operator<<(ostream &out, bignum a)
    {
        if (a.sign == 1 && !(a.size == 1 && a.head[0] == 0))
        {
            out << '-';
        }
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
        int fl = 0;
        if (ii[0] == '-')
            fl = 1;
        a.lim = ii.size() + 100;
        a.head = new char[a.lim];
        a.size = ii.size() - fl;
        a.sign = fl;
        for (int i = ii.size() - 1; i >= fl; i--)
        {
            a.head[ii.size() - i - 1] = ii[i] - '0';
        }
        return in;
    }
};
int main()
{
    //freopen("in.txt", "r", stdin);
    bignum a, b;
    cin >> a >> b;
    cout << a + b << endl;
    cout << a - b << endl;
}