#include <bits/stdc++.h>
using namespace std;
class location
{
protected:
    int x, y;

public:
    location(int xx, int yy) : x(xx), y(yy) {}
};
class Csharp
{
public:
    virtual bool is_click(int x, int y, int lx, int ly) const = 0;
};
class retangle : public Csharp
{
    int l, w;

public:
    bool is_click(int x, int y, int lx, int ly) const
    {
        if (x + l > lx && lx > x && y + w > ly && ly > y)
            return true;
        return false;
    }
    retangle(int x, int y) : l(x), w(y) {}
};
class circle : public Csharp
{
    double r;

public:
    bool is_click(int x, int y, int lx, int ly) const
    {
        if (r * r >= (x - lx) * (x - lx) + (y - ly) * (y - ly))
            return true;
        return false;
    }
    circle(double x) : r(x) {}
};
class GUIControl : public location
{
    Csharp *calc = NULL;

public:
    bool check(int lx, int ly)
    {
        return calc->is_click(x, y, lx, ly);
    }
    virtual void output() const = 0;
    virtual ~GUIControl()
    {
        delete calc;
    }
    GUIControl() : location(0, 0), calc(NULL) {}
    GUIControl(Csharp *a, int xx, int yy) : calc(a), location(xx, yy) {}
};
class Cmenu : public GUIControl
{
    string name;

public:
    void output() const { cout << "menu-" << name << " Clicked" << endl; }
    Cmenu(const string &a, Csharp *aa, int xx, int yy) : name(a), GUIControl(aa, xx, yy) {}
};
class Cbutton : public GUIControl
{
    string name;

public:
    void output() const { cout << "button-" << name << " Clicked" << endl; }
    Cbutton(const string &a, Csharp *aa, int xx, int yy) : name(a), GUIControl(aa, xx, yy) {}
};
int main()
{
    //  freopen("in.txt", "r", stdin);
    vector<GUIControl *> v;
    int n;
    cin >> n;
    string type, name, tmp;
    int a, b, c, d;
    double dd;
    GUIControl *now;
    Csharp *newsp;
    for (int i = 0; i < n; i++)
    {
        cin >> type >> name >> tmp;
        if (tmp == "rectangle")
        {
            cin >> a >> b >> c >> d;
            newsp = new retangle(c, d);
        }
        else
        {
            cin >> a >> b >> dd;
            newsp = new circle(dd);
        }
        if (type == "menu")
            now = new Cmenu(name, newsp, a, b);
        else
            now = new Cbutton(name, newsp, a, b);
        v.push_back(now);
    }
    while (cin >> tmp >> a >> b)
    {
        int f = 1;
        for (int i = 0; i < n; i++)
        {
            if (v[i]->check(a, b))
            {
                f = 0;
                v[i]->output();
                break;
            }
        }
        if (f)
            cout << "none hit" << endl;
    }
    return 0;
}