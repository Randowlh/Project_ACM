#include<stdio.h>
#include<math.h>
int main(){
	double X1, Y1,X2,Y2;
	while(scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2)!= EOF)
		printf("%.2f\n",sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2)));
}