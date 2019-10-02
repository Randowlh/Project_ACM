#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp,i;
	int m1 = 1,m2 = 1;
	for(i = 1; i <= 12; i++) {
		if(i == 1 || i == 2) {
			printf("第%d月的的兔子总数是：2只。\n",i);
		}else{
			temp = m2;
			m2 = m1 + m2;
			m1 = temp;
			printf("第%d月的的兔子总数是：%d只。\n",i,2*m2);
		}
	}
    return 0;
}
