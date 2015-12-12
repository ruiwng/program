#include  <stdio.h>

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		double sum = 0.0;
		for(int i = 0; i < n; ++i)
		{
			double x;
			scanf("%lf", &x);
			sum += x * (i + 1) * (n - i);
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}