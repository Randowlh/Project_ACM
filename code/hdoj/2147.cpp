
#include <cstdio>
#include<iostream>
using namespace std;
int main()
{
    int m, n;
    while (cin>>n>>m)
    {   
        if(n==0&&m==0)break;
        if (n%2==1 && m%2==1)
            printf("What a pity!\n");
        else
            printf("Wonderful!\n");
    }
    return 0;
}