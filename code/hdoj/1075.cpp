#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    map<string, string> M;
    M.clear();
    string tmp;
    cin >> tmp;
    if (tmp != "START")
        return 0;
    string tmp2;
    while (cin >> tmp)
    {
        if (tmp == "END")
            break;
        cin >> tmp2;
        M[tmp2] = tmp;
    }
    cin >> tmp;
    if (tmp != "START")
        return 0;
    char c;
    tmp.clear();
    c=getchar();
    while ((c = getchar()) != EOF)
    {
        if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
        {
            tmp.push_back(c);
            continue;
        }
        else
        {   
            if(tmp=="END")
         break;
            if (tmp.empty())
            {
                putchar(c);
                continue;
            }
            else if (M.count(tmp) == 0)
            {
                cout << tmp;
                putchar(c);
                tmp.clear();
                continue;
            }
            else
            {
                cout << M[tmp];
                tmp.clear();
                putchar(c);
            }
        }
    }
   // cout<<endl;
    return 0;
}