#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string a;
    while (true)
    {   cin>>a;
        if(a=="0")
        break;
        long long tmp = 0;
        for (int i = 0; i < a.size(); i++)
        {
            tmp += a[i] - '0';
        }
        while (tmp >=10)
        {
            a.clear();
            while (tmp != 0)
            {
                a.push_back(tmp % 10 + '0');
                tmp =tmp/10;
            }
            for (int i = 0; i < a.size(); i++)
            {
                tmp += a[i] - '0';
            }
        }
        printf("%d\n", tmp);
    }
    return 0;

}