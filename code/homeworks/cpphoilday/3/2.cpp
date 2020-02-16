#include <bits/stdc++.h>
using namespace std;
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
    node *head = NULL, *prh = NULL;
    int size;

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
        {
            pop();
        }
    }
    void make(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            insert(i);
        }
        size = n;
        node *now;
        now = head;
        while (now->next != NULL)
        {
            now = now->next;
        }
        prh = now;
        now->next = head;
        return;
    }
    vector<int> round(int n)
    {
        int cnt = 1;
        node *pr = prh;
        node *now = head;
        vector<int> ans;
        while (size > 0)
        {
            if (cnt == n)
            {
                size--;
                ans.push_back(now->v);
                node *t = now;
                now = now->next;
                pr->next = t->next;
                delete t;
                cnt = 1;
                continue;
            }
            cnt++;
            now = now->next;
            pr = pr->next;
        }
        return ans;
    }
} tmp;
int main()
{
    int m, n;
    cin >> m >> n;
    tmp.make(m);
    vector<int> a = tmp.round(n);
    for (int i = 0; i < (int)a.size(); i++)
    {
        cout << setw(4) << a[i];
    }
    return 0;
}