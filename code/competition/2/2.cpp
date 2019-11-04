#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string tmp1, tmp2;
long long a, b, c;
void print()
{
    if (a > 0)
    {
        cout << 'R';
        a--;
    }
    else if (b > 0)
    {
        cout << 'P';
        b--;
    }
    else{
        cout << 'S';
        c--;}
}
int main()
{
    long long  t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        long long  n;
        cin >> n;
        cin >> a >> b >> c;
        cin >> tmp1;
        long long  res = 0;
        tmp2.clear();
        for (int i = 0; i < tmp1.size(); i++)
        {
            if (tmp1[i] == 'R')
            {
                if (b > 0)
                {
                    b--;
                    res++;
                    tmp2.push_back('P');
                }
                else
                {
                    tmp2.push_back('x');
                }
            }
            else if (tmp1[i] == 'P')
            {
                if (c > 0)
                {
                    c--;
                    res++;
                    tmp2.push_back('S');
                }
                else
                {
                    tmp2.push_back('x');
                }
            }
            else if (tmp1[i] == 'S')
            {
                if (a > 0)
                {
                    a--;
                    res++;
                    tmp2.push_back('R');
                    //printf("lol");
                }
                else
                {
                    tmp2.push_back('x');
                    // printf("lol\n");
                }
            }
        }
        // printf("%d\n",res);
        long long mi = 0;
        if (n % 2 == 0)
            mi = n / 2;
        else
            mi = n / 2 + 1;
        if (res >= mi)
        {
            printf("YES\n");
            for (int i = 0; i < tmp2.size(); i++)
            {
                if (tmp2[i] == 'x')
                {
                    print();
                }
                else
                {
                    cout << tmp2[i];
                }
            }
            cout << endl;
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}