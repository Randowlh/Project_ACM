#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
double mp[40][40];
map<string,int> m;
int main()
{
    int k = 0;
    while (true)
    {
        k++;
        int n = 0;
        cin >> n;
        if(n==0)
        break;
        m.clear();
       // map<string, int> m;
       // m.clear();
        string tmp;
        for (int i = 1; i <= n; i++)
        {
            cin >> tmp;
            m[tmp] = i;
        }
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    mp[i][j] = 1;
                else
                    mp[i][j] = 0;
            }
        }
        string tmp1;
        double v;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp >> v >> tmp1;
            mp[m[tmp]][m[tmp1]] = v;
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {
                    if (mp[i][j] < mp[i][k] * mp[k][j])
                    {
                        mp[i][j] = mp[i][k] * mp[k][j];
                    }
                }
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            if (mp[i][i] > 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag==1){
            cout<<"Case "<<k<<": Yes"<<endl;
        }else{
            cout<<"Case "<<k<<": No"<<endl;
        }
        //  string tmp
    }
    return 0;
}