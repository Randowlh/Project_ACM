#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a, string b)
{
    if (a == b)
    {
        return true;
    }
    int fu1;
    int fu2;
    if (a[0] == '-')
        fu1 = 1;
    else
        fu1 = 0;
    if (b[0] == '-')
        fu2 = 1;
    else
        fu2 = 0;
    if (fu1 != fu2)
    {
        int flag = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] <= '9' && a[i] >= '0')
            {
                if (a[i] != '0')
                {
                    flag = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < b.size(); i++)
        {
            if (b[i] <= '9' && b[i] >= '0')
            {
                if (b[i] != '0')
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
            return false;
        else
            return true;
    }
    int offse = 0;
    if (fu1 == 1)
    {
        offse = 1;
    }
    string ta, tb;
    int flag = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (flag == 1)
        {
            if (a[i] <= '9' && a[i] >= '0')
            {
                ta.push_back(a[i]);
                continue;
            }
            else
            {
                break;
            }
        }
        else if (a[i] >= '1' && a[i] <= '9')
        {
            flag = 1;
            ta.push_back(a[i]);
            continue;
        }
    }
    if(ta.empty()) ta="0";
    flag = 0;
    for (int i = 0; i < b.size(); i++)
    {
        if (flag == 1)
        {
            if (b[i] <= '9' && b[i] >= '0')
            {
                tb.push_back(b[i]);
                continue;
            }
            else
            {
                break;
            }
        }
        else if (b[i] >= '1' && b[i] <= '9')
        {
            flag = 1;
            tb.push_back(b[i]);
            continue;
        }
    }
    if(tb.empty()) tb="0";
    if(ta!=tb){
        return false;
    }
    ta.clear();
    tb.clear();
    return true;
}
int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        if (cmp(a, b))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}