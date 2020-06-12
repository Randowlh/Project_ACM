int n;
int mp[510][510];
int ans = 0;
int pr[510];
int book[510];
bool dfs(int x)
{
    for (int i = 0; i < n; i++)
    {
        if (mp[x][i] && !book[i])
        {
            book[i] = 1;
            if (pr[i] == -1 || dfs(pr[i]))
            {
                pr[i] = x;
                return true;
            }
        }
    }
    return false;
}
void xyl()
{
    ans = 0;
    memset(pr, -1, sizeof(pr));
    for (int i = 0; i < n; i++)
    {
        memset(book, 0, sizeof(book));
        if (dfs(i))
        {
            ans++;
        }
    }
    return;
}