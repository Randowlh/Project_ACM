#include<stdio.h>

int main()

{
	int a[50];
	
	int x1,x2,x3,x4;
	
	int i,t;
	
	x1=0,x2=0,x3=0,x4=0;
	
	printf("请输入1-4的整数\n");
	
	for(i=0;i<50;i++)
	{
		scanf("%d",&a[i]);
		
		if(a[i]==-1) 
		 {
		  t=i;
		  break;
	}
	}
	
	for(i=0;i<=t;i++)
	{
	   switch(a[i])
	   {
	   	  case 1: x1++;
	   	  break;
	   	  
	   	  case 2: x2++;
	   	  break;
	   	  
	   	  case 3:x3++;
	   	  break;
	   	  
	   	  case 4:x4++;
	   	  break; 
	   }
		 
	}
	
	printf("1有%d个\n2有%d个\n3有%d个\n4有%d个",x1,x2,x3,x4);
	
	return 0;
	
 } 