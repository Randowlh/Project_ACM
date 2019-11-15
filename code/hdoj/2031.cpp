#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
char biao[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    int n;
    int r;
    while (cin >> n >> r)
    {
        string tmp;
        tmp.clear();
        int flag = 0;
        if (n < 0)
        {
            n = -n;
            flag = 1·】 
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
                   }
        while (n != 0)
        {
            tmp.push_back(biao[n % r]);
            n /= r;
        }
        if (flag)
        {
            cout << '-';
        }
        for (int i = tmp.size() - 1; i >= 0; i--)
        {
            cout << tmp[i];
    S    }
        cout << endl;
    }
    return 0;
}