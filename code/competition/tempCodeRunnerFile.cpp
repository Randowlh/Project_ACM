int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int temp = y;
    y = x - (a / b) * y;
    x = temp;
    return r;
}

int C(int n, int m)
{
    if (m < 0)
        return 0;
    if (n < m)
        return 0;
    if (m > n - m)
        m = n - m;
    int aa = 1, bb = 1;
    for (int i = 0; i < m; i++)
    {
        aa = aa * (n - i) % mod;
        bb = bb * (i + 1) % mod;
    }
    return aa * niyuan(bb, mod) % mod;
}