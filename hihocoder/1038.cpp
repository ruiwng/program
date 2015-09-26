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
			vector<int> temp = record;
			int new_bound = bound;
			for(int j = 0; j <= bound; ++j)
			{
				if(record[j] != -1)
				{
					int k = j + x;
					if(k <= m && record[j] + y > temp[k])
					{
						if(k > new_bound)
							new_bound = k;
						temp[k] = record[j] + y;
						if(temp[k] > max_value)
							max_value = temp[k];
					}
				}
			}
			bound = new_bound;
			record.swap(temp);
		}
		printf("%d\n", max_value);
	}
	return 0;
}