struct st_table
{
    int date[200100];
    int mx[200100][30];
    inline void RMQ(int num)
    {
        for (int i = 1; i <= num; i++)
            mx[i][0] = date[i];
        for (int j = 1; j < 20; ++j)
            for (int i = 1; i <= num; ++i)
                if (i + (1 << j) - 1 <= num)
                    mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
    inline int query(int l, int r)
    {
        int k = log(r - l + 1) / log(2);
        return max(mx[l][k], mx[r - (1 << k) + 1][k]);
    }
} b;