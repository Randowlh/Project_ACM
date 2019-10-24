#include <stdio.h>
#include <ctype.h>
int main()
{
    int n,i,f;
    char str[51];
    scanf("%d",&n);
    getchar();
    while (n--)
    {
        gets(str);
        f=1;
        if(str[0]!='_'&&!isalpha(str[0]))    f=0;
        i=1;
        while (str[i]!='\0'&&f==1)
        {
            if(str[i]!='_'&&!isalnum(str[i]))    f=0;
            i++;
        }
        if(f==0)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}