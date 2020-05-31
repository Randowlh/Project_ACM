#include <bits/stdc++.h>
using namespace std;
int main()
{
    string tmp;
    set<string> s;
    while (cin >> tmp)
        s.insert(tmp);
    cout << s.size() << endl;
}