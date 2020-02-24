#include <bits/stdc++.h>
using namespace std;
class link_list
{
private:
    struct node
    {
        int v;
        node *next = NULL;
    };
    node *head = NULL;

public:
    bool empty()
    {
        return head == NULL;
    }
    void insert(int v)
    {
        if (empty())
        {
            node *t = new node;
            t->v = v;
            t->next = NULL;
            head = t;
            return;
        }
        node *pr = NULL;
        node *now = head;
        while (now != NULL && now->v < v)
        {
            pr = now;
            now = now->next;
        }
        if (pr == NULL)
        {
            now = new node;
            now->v = v;
            now->next = head;
            head = now;
            return;
        }
        else if (now == NULL)
        {
            now = new node;
            now->v = v;
            now->next = NULL;
            pr->next = now;
            return;
        }
        else
        {
            node *t = new node;
            t->v = v;
            t->next = now;
            pr->next = t;
            return;
        }
    }
    int top()
    {
        return head->v;
    }
    void pop()
    {
        node *t;
        t = head;
        head = head->next;
        delete t;
        return;
    }
    void clear()
    {
        while (!empty())
            pop();
    }
    vector<int> bianli()
    {
        vector<int> ans;
        node *now = head;
        while (now != NULL)
        {
            ans.push_back(now->v);
            now = now->next;
        }
        return ans;
    }
} ou, ji;
int main()
{
    int t;
    while (cin >> t)
    {
        if (t == 0)
            break;
        if (t & 1)
        {
            ji.insert(t);
        }
        else
        {
            ou.insert(t);
        }
    }
    vector<int> a = ji.bianli();
    if (!a.empty())
    {
        for (int i = 0; i < (int)a.size() - 1; i++)
        {
            cout << a[i] << "->";
        }
        cout << *(a.end() - 1) << endl;
    }
    a = ou.bianli();
    if (!a.empty())
    {
        for (int i = 0; i < (int)a.size() - 1; i++)
        {
            cout << a[i] << "->";
        }
        cout << *(a.end() - 1) << endl;
    }
    while (!ou.empty())
    {
        ji.insert(ou.top());
        ou.pop();
    }
    a = ji.bianli();
    for (int i = 0; i < (int)a.size() - 1; i++)
    {
        cout << a[i] << "->";
    }
    cout << *(a.end() - 1) << endl;
    ji.clear();
    return 0;
}