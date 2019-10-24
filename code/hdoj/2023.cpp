#include<stdio.h>
int main()
{
    double score[51][6];
    int i,j,n,m,count;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        count=0;
        for(i=1; i<=n; i++)
        {
            score[i][0]=0;
            for(j=1; j<=m; j++)
            {
                scanf("%lf",&score[i][j]);
                score[i][0]+=score[i][j];
            }
            score[i][0]/=m;
        }
      
        for(j=1; j<=m; j++)
        {
            score[0][j]=0;
            for(i=1; i<=n; i++)
            {
                score[0][j]+=score[i][j];
            }
            score[0][j]/=n;
        }
      
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(score[i][j]<score[0][j])
                    break;
            }
            if(j>m)
                count++;
        }
      
        for(i=1; i<=n; i++)
            if(i==1)
                printf("%0.2lf",score[i][0]);
            else
                printf(" %0.2lf",score[i][0]);
        printf("\n");
        for(j=1; j<=m; j++)
            if(j==1)
                printf("%0.2lf",score[0][j]);
            else
                printf(" %0.2lf",score[0][j]);
        printf("\n");
        printf("%d\n\n",count);
    }
    return 0;
}