inline int pow(int x, int a, int mod)
{
    int ans = 0;
    int now = x;
    while (a != 0)
    {
        if (a & 1)
        {
            ans = ans * now % mod;
        }
        now = now * now % mod;
        a >>= 1;
    }
    return ans;
}