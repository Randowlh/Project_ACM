#include <bits/stdc++.h>
using namespace std;
class my_set
{
private:
    struct node
    {
        int date;
        node *next;
        node(int a = 0, node *p = nullptr) : next(p), date(a) {}
    };
    typedef long long ll;
    node *head;
    int size;
    void insert(const int &a)
    {
        if (head == nullptr)
        {
            head = new node(a);
            return;
        }
        node *p = head->next;
        node *pr = head;
        if (head->date > a)
        {
            node *tmp = new node(a, head);
            head = tmp;
            return;
        }
        if (head->date == a)
            return;
        while (p != nullptr)
        {
            if (p->date > a)
            {
                node *tmp = new node(a, p);
                pr->next = tmp;
                return;
            }
            if (p->date == a)
                return;
            pr = p;
            p = p->next;
        }
        pr->next = new node(a);
    }

public:
    ~my_set()
    {
        while (head != nullptr)
        {
            node *p = head;
            head = head->next;
            delete p;
        }
    }
    void clear()
    {
        while (head != nullptr)
        {
            node *p = head;
            head = head->next;
            delete p;
        }
    }
    my_set(const vector<int> &a)
    {
        for (int i = 0; i < a.size(); i++)
            insert(a[i]);
    }
    my_set(int a = 0)
    {
        head = nullptr;
        size = a;
    }
    my_set(const my_set &a)
    {
        clear();
        node *p = a.head;
        node **np = &head;
        while (p != nullptr)
        {
            *np = new node;
            (*np)->date = p->date;
            np = &(*np)->next;
            p = p->next;
        }
        *np = nullptr;
        return;
    }
    my_set(my_set &&a) noexcept
    {
        head = a.head;
        a.head = nullptr;
    }
    my_set &operator=(my_set &&a) noexcept
    {
        head = a.head;
        a.head = nullptr;
        return *this;
    }
    my_set &operator=(const my_set &a)
    {
        clear();
        node *p = a.head;
        node **np = &head;
        while (p != nullptr)
        {
            *np = new node;
            (*np)->date = p->date;
            np = &(*np)->next;
            p = p->next;
        }
        *np = nullptr;
        return *this;
    }
    my_set &operator+(const my_set &a)
    {
        node *p = head;
        node *q = a.head;
        static my_set ans;
        node **now = &ans.head;
        while (p != nullptr && q != nullptr)
        {
            if (p->date < q->date)
            {
                (*now) = new node(p->date);
                now = &(*now)->next;
                p = p->next;
            }
            else if (p->date > q->date)
            {
                (*now) = new node(q->date);
                now = &(*now)->next;
                q = q->next;
            }
            else
            {
                (*now) = new node(q->date);
                now = &(*now)->next;
                q = q->next;
                p = p->next;
            }
        }
        while (p != nullptr)
        {
            (*now) = new node(p->date);
            now = &(*now)->next;
            p = p->next;
        }
        while (q != nullptr)
        {
            (*now) = new node(q->date);
            now = &(*now)->next;
            q = q->next;
        }
        return ans;
    }
    my_set &operator*(const my_set &a)
    {
        node *p = a.head;
        node *q = head;
        static my_set ans;
        node **now = &ans.head;
        while (p != nullptr && q != nullptr)
        {
            if (p->date == q->date)
            {
                (*now) = new node(q->date);
                now = &(*now)->next;
                q = q->next;
                p = p->next;
            }
            else if (p->date < q->date)
                p = p->next;
            else
                q = q->next;
        }
        return ans;
    }
    my_set &operator-(const my_set &a)
    {
        node *p = head;
        node *q = a.head;
        static my_set ans;
        node **now = &ans.head;
        while (p != nullptr && q != nullptr)
        {
            if (p->date < q->date)
            {
                (*now) = new node(p->date);
                now = &(*now)->next;
                p = p->next;
            }
            else if (p->date > q->date)
            {
                q = q->next;
            }
            else
            {
                q = q->next;
                p = p->next;
            }
        }
        while (p != nullptr)
        {
            (*now) = new node(p->date);
            now = &(*now)->next;
            p = p->next;
        }
        return ans;
    }
    friend ostream &operator<<(ostream &out, my_set &a)
    {
        out << '{';
        node *p = a.head;
        int f = 0;
        while (p != nullptr)
        {
            if (f)
                out << ',';
            out << p->date;
            f = 1;
            p = p->next;
        }
        out << '}';
        return out;
    }
    friend istream &operator>>(istream &in, my_set &a)
    {
        int tmp;
        for (int i = 0; i < a.size; i++)
        {
            in >> tmp;
            a.insert(tmp);
        }
        return in;
    }
};
int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;
    my_set a(m), b(n);
    cin >> a >> b;
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a * b << endl;
    cout << a - b << endl;
    return 0;
}