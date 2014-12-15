#include  <stdio.h>

int main()
{
	int f;
	while(scanf("%d",&f)!=EOF)
	{
		printf("Celsius = %d\n",5*(f-32)/9);
	}
	return 0;
}
