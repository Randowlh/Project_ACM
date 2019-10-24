#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct node
{
    double a;
    int b;
    int e;
    bool operator<(const struct node a)
    {
        return this->a < a.a;
    }
} a[1000];
int n;
int m;
int s[1000];
int e[1000];
int calc(int a, int b)
{
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}
int main()
{
    while (true)
    {
        scanf("%d%d", &n, &m);
        if (m == -1 && n == -1)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &a[i].e, &a[i].b);
            a[i].a =(double)a[i].b/(double)calc(a[i].e,20);
        }
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&s[i],&e[i]);
        }
        sort(a, a + n);
        for(int i=0;i<n;i++){
            printf("a[%d] a:%f b:%d c:%d\n",i,a[i].a,a[i].b,a[i].e);
        }
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(m*20>=a[i].e){
                m-=calc(a[i].e,20);
                ans+=a[i].b;
                printf("m%d\n",m);
            }else{
                continue;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}