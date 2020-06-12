struct trie
{
    int next[100000][2], cnt;
    bool fl[100000];
    void clear()
    {
        memset(next, 0, sizeof(next));
        cnt = 0;
        memset(fl, false, sizeof(fl));
        return;
    }
    void insert(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - '0';
            if (next[p][c] == 0)
            {
                next[p][c] = ++cnt;
            }
            p = next[p][c];
        }
        fl[p] = true;
    }
    bool find(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - '0';
            if (next[p][c] == 0)
                return false;
            p = next[p][c];
        }
        return fl[p];
    }
    bool check(string a)
    {
        int p = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int c = a[i] - '0';
            if (next[p][c] == 0)
                return false;
            p = next[p][c];
        }
        return (next[p][0] == 0 && next[p][1] == 0);
    }
} node;