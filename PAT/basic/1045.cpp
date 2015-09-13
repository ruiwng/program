#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

int arry[2][100000];

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &arry[0][i]);
			arry[1][i] = arry[0][i];
		}

		sort(arry[0], arry[0] + n);

		int max_value = -1;
		vector<int> result;
		for(int i = 0; i < n; ++i)
		{
			if(arry[1][i] == arry[0][i] && arry[1][i] > max_value)
				result.push_back(arry[0][i]);
			if(arry[1][i] > max_value)
				max_value = arry[1][i];
		}

		int len = result.size();
		printf("%d\n", len);
		for(int i = 0; i < len; ++i)
			printf("%d%s", result[i], i == len - 1?"\n":" ");
		if(len == 0)
			printf("\n");
	}
	return 0;
}