#include <stdio.h>
int p1[1000];
int p2[1000];
int st[1000];
int taild;
int n;
int tail1, head1;
int tail2, head2;
int main()
{
    scanf("%d", &n);
    head1=0;
    tail1=0;
    head2=0;
    tail2=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p1[i]);
        tail1++;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p2[i]);
        tail2++;
    }
    while ((tail2 ^ head2) && (tail1 ^ head1))
    {
        int tmp = p1[head1];
        head1++;
        st[taild] = tmp;
        taild++;
        for (int i = 0; i < taild-1; i++)
        {
            if (tmp == st[i])
            {
                for (int j = taild-1; j >=i; j--)
                {
                    p1[tail1]=st[j];
                    tail1++;
                }
                taild=i;
                break;
            }
        }
        tmp = p2[head2];
        head2++;
        st[taild] = tmp;
        taild++;
        for (int i = 0; i < taild-1; i++)
        {
            if (tmp == st[i])
            {
                for (int j = taild-1; j >=i; j--)
                {
                    p2[tail2]=st[j];
                    tail2++;
                }
                taild=i;
                break;
            }
        }
    }
    if(head1!=tail1){
        printf("瀚瀚\n");
        for(int i=head1;i<tail1;i++){
            printf("%d ",p1[i]);
        }
        printf("\n");
    }else{
        printf("霆霆\n");
        for(int i=head2;i<tail2;i++){
            printf("%d ",p2[i]);
        }
        printf("\n");
    }
    return 0;
}
