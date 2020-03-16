#include <bits/stdc++.h>
using namespace std;
class selfset
{
public:
    int inlimit;
    vector<int> date;
    inline void set_inlimit(int a) { inlimit = a; }
    inline void insert(int a) { date.push_back(a); }
    selfset operator*(selfset &a)
    {
        selfset aa;
        vector<int> ans;
        sort(date.begin(), date.end());
        sort(a.date.begin(), a.date.end());
        set_intersection(date.begin(), date.end(), a.date.begin(), a.date.end(), insert_iterator<vector<int>>(ans, ans.begin()));
        sort(ans.begin(), ans.end());
        int len = unique(ans.begin(), ans.end()) - ans.begin();
        ans.resize(len);
        aa.date = ans;
        return aa;
    }
    selfset operator+(selfset &a)
    {
        selfset aa;
        vector<int> ans;
        sort(date.begin(), date.end());
        sort(a.date.begin(), a.date.end());
        set_union(date.begin(), date.end(), a.date.begin(), a.date.end(), insert_iterator<vector<int>>(ans, ans.begin()));
        sort(ans.begin(), ans.end());
        int len = unique(ans.begin(), ans.end()) - ans.begin();
        ans.resize(len);
        aa.date = ans;
        return aa;
    }
    selfset operator-(selfset &a)
    {
        selfset aa;
        vector<int> ans;
        sort(date.begin(), date.end());
        sort(a.date.begin(), a.date.end());
        set_difference(date.begin(), date.end(), a.date.begin(), a.date.end(), insert_iterator<vector<int>>(ans, ans.begin()));
        sort(ans.begin(), ans.end());
        int len = unique(ans.begin(), ans.end()) - ans.begin();
        ans.resize(len);
        aa.date = ans;
        return aa;
    }
    friend ostream &operator<<(ostream &out, selfset s)
    {
        out << "{";
        if (s.date.empty())
        {
            out << "}" << endl;
            return out;
        }
        sort(s.date.begin(), s.date.end());
        for (int i = 0; i < (int)s.date.size() - 1; i++)
        {
            out << s.date[i] << ",";
        }
        out << s.date[s.date.size() - 1] << "}";
        out << endl;
        return out;
    }
    friend istream &operator>>(istream &in, selfset &s)
    {
        int tmp;
        for (int i = 0; i < s.inlimit; i++)
        {
            in >> tmp;
            s.date.push_back(tmp);
        }
        return in;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    selfset a, b;
    a.set_inlimit(n);
    b.set_inlimit(m);
    cin >> a;
    cin >> b;
    cout << a;
    cout << b;
    cout << a + b;
    cout << a * b;
    cout << a - b;
}