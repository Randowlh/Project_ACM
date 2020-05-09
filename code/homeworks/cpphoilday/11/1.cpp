#include <bits/stdc++.h>
using namespace std;
template <typename T>
class myqueue
{
private:
    struct node
    {
        T date;
        node *next;
        node(T &da) : date(da), next(NULL) {}
        node() : next(NULL) {}
    };
    node *head = NULL;
    node *tail = NULL;

public:
    ~myqueue()
    {
        node *p = nullptr;
        while (head != nullptr)
        {
            p = head;
            head = head->next;
            delete p;
        }
    }
    myqueue()
    {
        tail = nullptr;
        head = nullptr;
    }
    myqueue(const myqueue &a)
    {
        tail = nullptr;
        node *q = a.head;
        node **p = &head;
        while (q != nullptr)
        {
            *p = new node;
            (*p)->date = q->date;
            tail = *p;
            p = &(*p)->next;
            q = q->next;
        }
    }
    myqueue(myqueue &&a) noexcept
    {
        head = a.head;
        tail = a.tail;
        a.head = nullptr;
    }
    myqueue &operator=(const myqueue &a)
    {
        node *q = a.head;
        node **p = &head;
        while (q != nullptr)
        {
            *p = new node;
            (*p)->date = q->date;
            p = &(*p)->next;
            q = q->next;
        }
        return *this;
    }
    myqueue &operator=(myqueue &&a)
    {
        head = a.head;
        tail = a.tail;
        a.head = nullptr;
        return *this;
    }
    inline bool empty() const { return head == nullptr; }
    void push(T &a)
    {
        if (head == nullptr)
        {
            head = new node(a);
            tail = head;
            return;
        }
        tail->next = new node;
        (tail->next)->date = a;
        tail = tail->next;
    }
    T front() { return *head; }
    void pop()
    {
        node *p = head;
        head = head->next;
        cout << p->date << ' ';
        delete p;
    }
    vector<T> bianli()
    {
        vector<T> ans;
        node *p = head;
        while (p != nullptr)
        {
            ans.push_back(p->date);
            p = p->next;
        }
        return ans;
    }
    void out()
    {
        node *p = head;
        while (p != nullptr)
        {
            cout << p->date << ' ';
            p = p->next;
        }
    }
};
int main()
{
    //freopen("in.txt", "r", stdin);
    string tmp;
    cin >> tmp;
    if (tmp == "string")
    {
        vector<myqueue<string>> date(4);
        int n;
        cout << "Start:" << endl;
        cin >> n;
        int a, c;
        string b;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            cin >> a;
            if (tmp == "pop")
            {
                date[a - 1].pop();
                continue;
            }
            if (tmp == "assign")
            {
                cin >> c;
                date[c - 1] = date[a - 1];
                continue;
            }
            cin >> b;
            date[a - 1].push(b);
        }
        cout << endl;
        date[3] = date[0];
        cout << "Final:" << endl;
        for (int i = 0; i < 4; i++)
        {
            date[i].out();
            cout << endl;
        }
    }
    else if (tmp == "int")
    {
        vector<myqueue<int>> date(4);
        int n;
        cout << "Start:" << endl;
        cin >> n;
        int a, b, c;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            cin >> a;
            if (tmp == "pop")
            {
                date[a - 1].pop();
                continue;
            }
            if (tmp == "assign")
            {
                cin >> c;
                date[c - 1] = date[a - 1];
                continue;
            }
            cin >> b;
            date[a - 1].push(b);
            // cout << a << " =";
            // date[a - 1].out();
            // cout << endl;
        }
        cout << endl;
        date[3] = date[0];
        cout << "Final:" << endl;
        for (int i = 0; i < 4; i++)
        {
            date[i].out();
            cout << endl;
        }
    }
}