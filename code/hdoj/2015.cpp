#include<stdio.h>
int main()
{
 int n,m,i,a[100],b[100],p,k;
 while(scanf("%d %d",&n,&m)!=EOF)
 {
   
  k=n/m; 
  p=n%m; 
       if(p!=0)  
  {
   for(i=1;i<=k;i++)
    a[i]=i*m*i*m+i*m;  
     a[k+1]=n*n+n;
   b[1]=a[1]/m;
     for(i=2;i<=k;i++)
      b[i]=(a[i]-a[i-1])/m;
     b[k+1]=(a[k+1]-a[k])/(n-k*m);
     printf("%d",b[1]);
     for(i=2;i<=k;i++)
      printf(" %d",b[i]);
     printf(" %d\n",b[k+1]);
  }
  if(p==0)
  {
   for(i=1;i<=k;i++)
      a[i]=i*m*i*m+i*m;
   b[1]=a[1]/m;
     for(i=2;i<=k;i++)
      b[i]=(a[i]-a[i-1])/m;
     printf("%d",b[1]);
     for(i=2;i<=k;i++)
      printf(" %d",b[i]);
     printf("\n");
  }
 }
 return 0;
}