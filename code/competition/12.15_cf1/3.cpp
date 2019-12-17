#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
const int inf = 0x7FFFFFFF;
long long mod = 1000000007;
string s;
int x;
int t;
int main()
{
    cin >> t;
    for (int q = 0; q < t; q++)
    {
        cin >> x >> s;
        int pos = 0;
        long long now = s.size();
        // long long tol=s.size();
        //cout<<tol<<'s'<<endl;
        long long l = s.size();
        //int flag=0;
        for (int i = 0; i < x; i++)
        {
            int tms = s[i] - '0';
            if (l < x)
            {
                for (int j = 0; j < tms - 1; j++)
                {
                    if (s.size() < x)
                    {
                        for (int k = i + 1; k < l; k++)
                        {
                            s.push_back(s[k]);
                        }
                    }
                }
            }
            long long now = (l-i-1+mod)%mod;
            l=(i+1+now*tms%mod)%mod;
        }
        cout << l << endl;
    }
}