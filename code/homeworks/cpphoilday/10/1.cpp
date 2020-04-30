#include <bits/stdc++.h>
using namespace std;
class GUIcontrol
{
protected:
    virtual bool click() const = 0;
};
class Csharp
{
protected:
    virtual bool is_click(int x, int y) const = 0;
};
class retangle : public Csharp
{
    int l, w;
    bool is_click(int x, int y, int lx, int ly)
    {
        if ()
    }
};
class GUIControl : public GUIcontrol
{
    int x;
    int y;
    Csharp *calc;
};
int main()
{
}