#include <bits/stdc++.h>
using namespace std;
#define bug puts("here");
class mx
{
private:
    int sz;

public:
    int *a;
    int size()
    {
        return sz;
    }
    void make(int n)
    {
        sz = n;
        a = new int[n * n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                *(a + n * i + j) = 0;
        }
        *(a + n / 2) = 1;
        int now = 2;
        int pr = n / 2;
        while (now <= n * n)
        {
            if (pr < n)
            {
                if ((pr + 1 + (n - 1) * n) < n * n && *(a + pr + 1 + (n - 1) * n) == 0)
                {
                    *(a + pr + 1 + (n - 1) * n) = now;
                    pr = pr + 1 + (n - 1) * n;
                }
                else
                {
                    *(a + pr + n) = now;
                    pr = pr + n;
                }
                now++;
                continue;
            }
            else if (pr % n == n - 1)
            {
                if (*(a + pr - 2 * n + 1) == 0)
                {
                    *(a + pr - 2 * n + 1) = now;
                    now++;
                    pr = pr - 2 * n + 1;
                }
                else if (pr + n < n * n)
                {
                    *(a + pr + n) = now;
                    pr = pr + n;
                    now++;
                }
                else
                {
                    *(a + (pr % n)) = now;
                    pr = pr % n;
                    now++;
                }
                continue;
            }
            else
            {
                if (*(a + pr - n + 1) == 0)
                {
                    *(a + pr - n + 1) = now;
                    pr = pr - n + 1;
                    now++;
                }
                else
                {
                    *(a + pr + n) = now;
                    pr = pr + n;
                    now++;
                }
            }
        }
    }
    void clear()
    {
        delete[] a;
    }
};
