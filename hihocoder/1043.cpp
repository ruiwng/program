#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF)
	{
		vector<int> record(m + 1, -1);
		record[0] = 0;

		int bound = 0;
		int max_value = 0;
		for(int i = 0; i < n; ++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			for(int j = 0; j <= bound && j + x <= m; ++j)
			{
				if(record[j] != -1)
				{
					int temp = j + x;
					if(record[j] + y > record[temp])
					{
						if(temp > bound)
							bound = temp;
						record[temp] = record[j] +y;
						if(record[temp] > max_value)
							max_value = record[temp];
					}
				}
			}
		}
		printf("%d\n", max_value);
	}
	return 0;
}