#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n;
    int now;
    int tmp;
    int tol;
    while (true)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        int now = 0;
        tol = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            if (now > tmp)
            {
                tol+=(now-tmp)*4;
                now=tmp;
                tol+=5;
            }else if(tmp>now){
                tol+=(tmp-now)*6;
                now=tmp;
                tol+=5;
            }else{
                tol+=5;
            }
        }
        printf("%d\n",tol);
    }
    return 0;
}