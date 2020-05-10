#include <bits/stdc++.h>
using namespace std;
int _;
template <typename T>
class Que
{
public:
    deque<T> x;
    void push(T w)
    {
        x.push_back(w);
    }
    void pop()
    {
        x.pop_front();
    }
    void assign(Que &a)
    {
        x = a.x;
    }
    T top()
    {
        return x.front();
    }
    bool empty()
    {
        return !x.size();
    }
};
template <typename T>
void work()
{
    string str;
    int y, z;
    T x;
    Que<T> q[4];
    cout << "Start:" << endl;
    while (_--)
    {
        cin >> str >> y;
        y--;
        if (str == "assign")
        {
            cin >> z;
            z--;
            q[z].assign(q[y]);
        }
        else if (str == "push")
        {
            cin >> x;
            q[y].push(x);
        }
        else if (!q[y].empty())
        {
            cout << "##";
            cout << q[y].top() << ' ';
            q[y].pop();
        }
        cout << _ << endl;
    }
    cout << endl
         << "Final:" << endl;
    q[3].assign(q[0]);
    for (int i = 0; i < 4; i++)
    {
        while (!q[i].empty())
        {
            cout << q[i].top() << ' ';
            q[i].pop();
        }
        cout << endl;
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    string str;
    cin >> str >> _;
    if (str == "int")
        work<int>();
    else
        work<string>();
    return 0;
}
