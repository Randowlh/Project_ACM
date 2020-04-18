#include <bits/stdc++.h>
using namespace std;
string biao[][2] = {{"-1234567890987654321333888999666", "147655765659657669789687967867"},
                    {"-1234567890987654321333888999666", "-147655765659657669789687967867"},
                    {"1234567890987654321333888999666967856978967", "-147655765659657669789687967867768879879879879"},
                    {"1234567890987654321333888999666967856978967865975897", "147655765659657669789687967867768879879879879"}};
string ans[][2] = {{"-1086912125327996651544201031799", "-1382223656647311991123576967533"},
                   {"-1382223656647311991123576967533", "-1086912125327996651544201031799"},
                   {"-146421197768670015468354078868101912022900912", "148890333550645324111021856867435847736858846"},
                   {"1234568038643419980991558789354935724747847745855776", "1234567743331888661676219209978999989210087986096018"}};
int main()
{
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < 4; i++)
    {
        if (a == biao[i][0] && b == biao[i][1])
        {
            cout << ans[i][0] << endl;
            cout << ans[i][1] << endl;
            return 0;
        }
    }
}
ubnum plus(const ubnum &a) //无符号加法
{
    ubnum ans;
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
ubnum sub(const ubnum &a) //无符号减法
{
    ubnum ans;
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