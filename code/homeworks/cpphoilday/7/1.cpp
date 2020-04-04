#include <bits/stdc++.h>
using namespace std;
class bignum
{
private:
    struct node
    {
        int size;
        int limits;
        int sign;
    } date;
    char *head;

public:
    int size()
    {
        return date.size;
    }
    bignum(int a = 0)
    {
        if (a < 0)
            date.sign = 1;
        else
            date.sign = 0;
        a = abs(a);
        head = new char[100];
        int cnt = 0;
        while (a != 0)
        {
            head[cnt] = a % 10;
            a /= 10;
        }
        date.size = cnt + 1;
        for (int i = 0; i < cnt / 2; i++)
        {
            swap(head[i], head[cnt - i]);
        }
        date.limits = 100;
        return;
    }
    bignum &operator=(bignum &a)
    {
        date = a.date;
        delete[] head;
        head = new char[date.limits];
        for (int i = 0; i < date.size; i++)
        {
            head[i] = a.head[i];
        }
        return;
    }
    bignum &operator=(bignum &&a) noexcept
    {
        date = a.date;
        delete[] head;
        head = a.head;
        a.head = nullptr;
        return;
    }
    bignum(bignum &a)
    {
        date = a.date;
        head = new char[date.limits];
        for (int i = 0; i < date.size; i++)
        {
            head[i] = a.head[i];
        }
        return;
    }
    bignum(bignum &&a) noexcept
    {
        date = a.date;
        a.head = nullptr;
        return;
    }
    ~bignum()
    {
        delete[] head;
        return;
    }
    bignum &operator+(bignum &a)
    {
        bignum ans;
        if (max(date.limits, a.date.limits) - max(a.date.size, date.size) < 10)
        {
            ans.head = new char[max(date.limits, a.date.limits) + 10];
        }
    }
};
int main()
{
    bignum a(1213);
}