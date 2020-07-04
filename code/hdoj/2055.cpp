#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        char c;
        int y;
        cin >> c >> y;
        if (c >= 'a' && c <= 'z')
        {
            cout << y - (c - 'a' + 1) << endl;
        }
        else
        {
            cout << y + (c - 'A' + 1) << endl;
        }
    }
}