#include  <stdio.h>
#include  <string.h>

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		int record[1001];
		memset(record, 0, sizeof(record));
		int max_score = 0;
		int max_number;
		for(int i = 0; i < n; ++i)
		{
			int number, member, score;
			scanf("%d-%d%d", &number, &member, &score);
			record[number] += score;
			if(record[number] > max_score)
			{
				max_score = record[number];
				max_number = number;
			}
		}

		printf("%d %d\n", max_number, max_score);
	}
	return 0;
}