#include <bits/stdc++.h>
using namespace std;
class stk
{
private:
    int arr[10000];
    int tail = 0;

public:
    inline int size() { return tail; }
    inline void pop() { tail--; }
    inline void push(int t)
    {
        arr[tail] = t;
        tail++;
    }
    inline int top() { return arr[tail - 1]; }
    inline int empty() { return tail == 0; }
};
int main()
{
    stk a[3];
    int f, s;
    while (cin >> f >> s)
    {
        a[f].push(s);
    }
    while (!a[1].empty())
    {
        cout << a[1].top() << ' ';
        a[1].pop();
    }
    cout << endl;
    while (!a[2].empty())
    {
        cout << a[2].top() << ' ';
        a[2].pop();
    }
    cout << endl;
    return 0;
}