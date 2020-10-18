#include<stdio.h> 
int main(void)
{
	int x,y,z,m,n,a;
	
	printf("Enter m:");
	printf("Enter n:");
	while(scanf ("%d %d",&m,&n)!=EOF){
		
	    for (a=m; a<=n;a++) {
	    x=a/100; 
		y=((a%100)/10); 
		z=((a%100)%10);
		if (a==x*x*x+y*y*y+z*z*z){
				printf("%d  ",a);
		}
		else
	      printf ("no\n");
	   }
   }	
	return 0;
}