#include  <stdio.h>

struct pat
{
	long long number;
	int seat;
};

pat pat_array[1001];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
		{
			long long x;
			int y, z;
			scanf("%lld%d%d", &x, &y, &z);
			pat_array[y].number = x;
			pat_array[y].seat = z;
		}

		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; ++i)
		{
			int temp;
			scanf("%d", &temp);
			printf("%lld %d\n", pat_array[temp].number, pat_array[temp].seat);
		}
	}
	return 0;
}