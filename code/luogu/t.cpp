#include <stdio.h>
#include <string.h>
int main()
{
	int i = 0, j = 0, t;
	int sum = 0;
	char a[500001], b[500001],s;

	gets(a);
	
	for(i = 0; i < strlen(a); i++)
	{
		if(a[i] != ' ')
		{
			b[j++] = a[i];	
		}
		else if(a[i] == ' ' && a[i + 1] == ' ')
		{
			continue;
		}
		else if(a[i] == ' ' && a[i + 1] != ' ' && i != 0 && i != strlen(a)-1 )  
		{
			b[j++] = a[i];
		}
	}
	printf("%s\n", b);
	for(i = j - 1; i >= 0; i--)
	{
		if(b[i] != ' ')
		{
			sum += 1;
		}
		else
		{
			for(t = i + 1; t < i + 1 + sum; t++)
			{
				printf("%c", b[t]);
			}
			printf(" k ");
			sum = 0;
		}
	}
	
	for(t = i + 1; t < i + 1 + sum; t++)
	{
		printf("%c", b[t]);
	}
    printf(" h\n");
	return 0;
}