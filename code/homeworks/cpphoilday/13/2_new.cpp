#include <bits/stdc++.h>
using namespace std;
class stu
{
private:
    string name;
    int ID;

public:
    stu(string n = "", int id = 0) : name(n), ID(id) {}
    friend ostream &operator<<(ostream &out, stu &a)
    {
        out << a.ID << ' ' << a.name;
        return out;
    }
};
class org
{
public:
    virtual void add_stu(shared_ptr<stu> a) {}
    virtual bool check(string &n, int flag) const = 0;
    virtual void output() {}
};
class cls : public org
{
private:
    string name;
    vector<shared_ptr<stu>> members;

public:
    cls(string n) : name(n) {}
    void add_stu(shared_ptr<stu> a)
    {
        members.push_back(a);
    }
    void output()
    {
        cout << "class" << ' ' << name << ':' << endl;
        for (int i = 0; i < (int)members.size(); i++)
        {
            cout << *(members[i]) << endl;
        }
        cout << endl;
    }
    bool check(string &n, int flag) const
    {
        if (flag)
            return false;
        return name == n;
    }
};
class team : public org
{
private:
    string name;
    vector<shared_ptr<stu>> members;

public:
    team(string n) : name(n) {}
    void add_stu(shared_ptr<stu> a)
    {
        members.push_back(a);
    }
    void output()
    {
        cout << name << " team" << ':' << endl;
        for (int i = 0; i < (int)members.size(); i++)
        {
            cout << *(members[i]) << endl;
        }
        cout << endl;
    }
    bool check(string &n, int flag) const
    {
        if (!flag)
            return false;
        return name == n;
    }
};
int main()
{
    int now = 10000;
    // freopen("in.txt", "r", stdin);
    string tmp, tmp2;
    int tt;
    vector<shared_ptr<stu>> Students;
    vector<shared_ptr<org>> lst;
    while (cin >> tmp)
    {
        if (tmp == "append")
        {
            cin >> tmp;
            auto p = make_shared<stu>(tmp, now);
            Students.push_back(p);
            now++;
        }
        else if (tmp == "create")
        {
            cin >> tmp >> tmp2;
            shared_ptr<org> p = NULL;
            if (tmp == "class")
                p = make_shared<cls>(tmp2);
            else
                p = make_shared<team>(tmp2);
            lst.push_back(p);
        }
        else if (tmp == "join")
        {
            cin >> tmp >> tmp2 >> tt;
            int flag = 0;
            if (tmp == "team")
                flag = 1;
            for (int i = 0; i < (int)lst.size(); i++)
            {
                if (lst[i]->check(tmp2, flag))
                {
                    lst[i]->add_stu(Students[tt - 10000]);
                    break;
                }
            }
        }
    }
    cout << "student list:" << endl;
    for (int i = 0; i < (int)Students.size(); i++)
        cout << (*Students[i]) << endl;
    cout << endl;
    for (int i = 0; i < (int)lst.size(); i++)
        lst[i]->output();
    return 0;
}