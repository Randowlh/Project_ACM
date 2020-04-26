#include <bits/stdc++.h>
using namespace std;
class CUIControl
{
public:
    virtual void Click() const = 0;
};
class menu : public CUIControl
{
    string name;

public:
    menu(string n) : name(n) {}
    void Click() const { cout << "menu-" << name << " Clicked" << endl; }
};
class button : public CUIControl
{
    string name;

public:
    button(string n) : name(n) {}
    void Click() const { cout << "button-" << name << " Clicked" << endl; }
};
CUIControl *arr[1000];
int tail;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    tail = 1;
    int n;
    cin >> n;
    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == "menu")
        {
            cin >> tmp;
            CUIControl *t = new menu(tmp);
            arr[tail] = t;
            tail++;
        }
        else if (tmp == "button")
        {
            cin >> tmp;
            CUIControl *t = new button(tmp);
            arr[tail] = t;
            tail++;
        }
    }
    while (cin >> tmp >> n)
    {
        arr[n]->Click();
    }
    return 0;
}