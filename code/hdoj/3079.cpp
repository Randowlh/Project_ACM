#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
char biao[] = {'a', 'e', 'i', 'o', 'u'};
int main()
{
    int t;
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        string tmp;
        cin >> tmp;
        for (int i = 0; i < tmp.size(); i++)
        {
            if (tmp[i] >= 'A' && tmp[i] <= 'Z')
            {
                tmp[i] -= 'A';
                tmp[i] += 'a';
            }
        }
        for (int i = 0; i < tmp.size(); i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (tmp[i]==biao[j]){
                    tmp[i]-='a';
                    tmp[i]+='A';
                    break;
                }
            }
        }
        cout<<tmp<<endl;
    }
    return 0;
}