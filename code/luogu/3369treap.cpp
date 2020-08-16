#include <bits/stdc++.h>
#include <random>
using namespace std;
const int maxn = 110000;
mt19937 rnd(114514);
priority_queue
struct fhq_treap
{
    struct node
    {
        int l, r;
        int val, key;
        int size;
    } fhq[maxn];
    int cnt, root;
    inline int newnode(int val)
    {
        fhq[++cnt].val = val;
        fhq[cnt].key = rnd();
        fhq[cnt].size = 1;
        fhq[cnt].l = fhq[cnt].r = 0;
        return cnt;
    }
    void split(int now,int val,int &x,int &y){
        priority_queue
    }
};
int main()
{
    cout << "hello write" << endl;
}