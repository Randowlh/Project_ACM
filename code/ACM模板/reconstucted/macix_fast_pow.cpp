int n;
int mod;
struct node
{
    // int n;
    int date[100][100];
    node operator*(node a)
    {
        node x;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int ans = 0;
                for (int k = 0; k < n; k++)
                {
                    ans = ans + date[i][k] * a.date[k][j];
                    ans %= mod;
                }
                x.date[i][j] = ans;
            }
        return x;
    }
    node operator=(node a)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                date[i][j] = a.date[i][j];
        return *this;
    }
} cst, e;
inline node pow(node x, int a, int mod)
{
    node ans = e;
    node now = x;
    while (a != 0)
    {
        if (a & 1)
        {
            ans = ans * now;
        }
        now = now * now;
        a >>= 1;
    }
    return ans;
}