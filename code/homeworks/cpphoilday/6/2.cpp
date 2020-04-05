#include <iostream>
#include <algorithm>
using namespace std;

class CStack
{
public:
    CStack() : m_sp(nullptr) //构造函数
    {
    }
    ~CStack(); //析构函数
    CStack(const CStack &rhs);
    CStack &operator=(const CStack &rhs);
    CStack(CStack &&rhs);
    CStack &operator=(CStack &&rhs);

    void push(int x);   //入栈
    bool empty() const; //判栈空
    int top() const;    //非空时取栈顶元素
    void pop();         //非空时出栈
private:
    struct Node //  内嵌结点类
    {
        Node() : next(nullptr) {} //结点建立时指针域值为nullptr
        int data;
        Node *next;
    };
    Node *m_sp; //链表首指针
};

CStack::~CStack()
{
    //删除所有结点
    while (m_sp != nullptr)
    {
        Node *p = m_sp; //临时指针变量p
        m_sp = m_sp->next;
        delete p; //删除p所指结点，删除后不可使用该结点
    }
}

void CStack::push(int x)
{
    Node *p = new Node; //动态分配1个结点
    p->data = x;
    p->next = m_sp;
    m_sp = p;
}

bool CStack::empty() const
{
    return (m_sp == nullptr);
}
int CStack::top() const
{
    return m_sp->data;
}

void CStack::pop()
{
    Node *p = m_sp;
    m_sp = p->next;
    delete p;
}

//将栈内所有元素出栈并显示
void DumpStack(CStack &S)
{
    while (!S.empty())
    {
        int x;
        x = S.top();
        cout << x << "  ";
        S.pop();
    }
    cout << endl;
}
//栈的拷贝构造代码
CStack::CStack(const CStack &rhs)
{
    Node *p = rhs.m_sp;
    Node **np = &m_sp;
    while (p != nullptr)
    {
        *np = new Node;
        (*np)->data = p->data;
        np = &(*np)->next;
        p = p->next;
    }
    *np = nullptr;
    return;
}
//栈的复制赋值代码
CStack &CStack::operator=(const CStack &rhs)
{
    Node *p = rhs.m_sp;
    Node **np = &m_sp;
    while (p != nullptr)
    {
        *np = new Node;
        (*np)->data = p->data;
        np = &(*np)->next;
        p = p->next;
    }
    *np = nullptr;
    return *this;
}
//栈的移动构造代码
CStack::CStack(CStack &&rhs)
{
    m_sp = rhs.m_sp;
    rhs.m_sp = nullptr;
    return;
}
//栈的移动赋值代码
CStack &CStack::operator=(CStack &&rhs)
{
    m_sp = rhs.m_sp;
    rhs.m_sp = nullptr;
    return *this;
}
//测试函数
int main()
{
    freopen("in.txt", "r", stdin);
    CStack S1, S2;
    int n;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        S1.push(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        S2.push(tmp);
    }
    CStack S3 = move(S1);
    CStack S4 = S2;
    DumpStack(S3);
    DumpStack(S4);
}