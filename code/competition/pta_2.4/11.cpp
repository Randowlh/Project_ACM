#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
string ers1, ers2, name1, name2;
map<string, int> J;
map<string, string> M;
map<string, string> X;
bool check(string a, string b)
{ // cout<<"sad"<<endl;
    set<string> s;
    s.clear();
    string ta, tb;
    ta = a;
    tb = b;
    for (int i = 0; i < 999999; i++)
    {
        s.insert(a);
        if (M.count(a) == 0)
            break;
        a = M[a];
    }
    //s.insert(a);
    //cout<<a<<endl;
    for (int i = 0; i < 4; i++)
    {
        if (s.count(b) != 0)
        {
            return false;
        }
        if (M.count(b) == 0)
            break;
        b = M[b];
    }
    s.clear();
    a = ta;
    b = tb;
    for (int i = 0; i < 999999; i++)
    {
        s.insert(b);
        if (M.count(b) == 0)
            break;
        b = M[b];
    }
    //s.insert(a);
    //cout<<a<<endl;
    for (int i = 0; i < 4; i++)
    {
        if (s.count(a) != 0)
        {
            return false;
        }
        if (M.count(a) == 0)
            break;
        a = M[a];
    }
    return true;
}
void work()
{
    int n;
    cin >> n;
    string name;
    string lk;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> lk;
        if (lk.size() < 7)
        {
            if (lk[lk.size() - 1] == 'j')
                J[name] = 1;
            else
                J[name] = 2;
            X[name] = lk;
        }
        else if (lk.substr(lk.size() - 7, 999) == "sdottir")
        {
            J[name] = 2;
            M[name] = lk.substr(0, lk.size() - 7);
            X[name] = M[name];
        }
        else
        {
            //J[name] = 1;
            if (lk.size() >= 4 && lk.substr(lk.size() - 4, 999) == "sson")
            {
                M[name] = lk.substr(0, lk.size() - 4);
                X[name] = M[name];
                J[name] = 1;
            }
            else
            {
                X[name] = lk;
                if (lk[lk.size() - 1] == 'j')
                    J[name] = 2;
                else
                    J[name] = 1;
            }
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> name1 >> ers1 >> name2 >> ers2;
        if (J.count(name1) == 0 || J.count(name2) == 0)
        {
            cout << "NA" << endl;
            continue;
        }
        if (X[name1] != ers1 || X[name2] != ers2)
        {
            cout << "NA" << endl;
            continue;
        }
        if (J[name1] == J[name2])
        {
            cout << "Whatever" << endl;
            continue;
        }
        if (check(name1, name2))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return;
}
int main()
{
   //  freopen("in.txt", "r", stdin);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        work();
    }
    return 0;
}
/*
Yes
No
No
Whatever
Whatever
NA
*/