#include  <stdio.h>
#include  <math.h>
#include  <vector>
#include  <algorithm>
#include  <functional>
using namespace std;

int num[10010];

int main()
{
	int N;
	while(scanf("%d", &N) != EOF)
	{
		int m = sqrt((long long)N);
		while(N % m != 0)
			++m;
		int n = N / m;
		if(m < n)
		{
			int temp = m;
			m = n;
			n = temp;
		}

		vector<vector<int> > arry(m, vector<int>(n));

		for(int i = 0; i < N; ++i)
			scanf("%d", &num[i]);

		sort(num, num + N, greater<int>());

		int index = 0;
		int left = 0, right = n - 1;
		int top = 0, bottom = m - 1;
		while(true)
		{
			for(int i = left; i <= right; ++i)
				arry[top][i] = num[index++];
			if(++top > bottom)
				break;
			for(int i = top; i <= bottom; ++i)
				arry[i][right] = num[index++];
			if(--right < left)
				break;
			for(int i = right; i >=left; --i)
				arry[bottom][i] = num[index++];
			if(--bottom < top)
				break;
			for(int i = bottom; i >= top; --i)
				arry[i][left] = num[index++];
			if(++left > right)
				break;
		}

		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
				printf("%d%c", arry[i][j], j == n - 1?'\n':' ');
		}
	}
}