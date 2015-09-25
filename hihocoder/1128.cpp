#include  <stdio.h>
#include  <algorithm>
#include  <vector>
using namespace std;

int main()
{
	int n, obj;
	while(scanf("%d%d", &n, &obj) != EOF)
	{
		vector<int> info_array;
		info_array.reserve(n);

		for(int i = 0; i < n; ++i)
		{
			int temp;
			scanf("%d", &temp);
			info_array.push_back(temp);
		}
		sort(info_array.begin(), info_array.end());

		vector<int>::iterator iter = lower_bound(info_array.begin(), info_array.end(), obj);

		if(iter == info_array.end() || *iter != obj)
			printf("-1\n");
		else
			printf("%d\n", iter - info_array.begin() + 1);
	}
	return 0;
}