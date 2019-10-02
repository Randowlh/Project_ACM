#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[4][4], i, j, t;
    printf("Input:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Output:\n");
    for (i = 0; i < 4; i++) {
        for (j = 3; j >=i ; j--) {
            t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
