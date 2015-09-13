#include  <stdio.h>
#include  <vector>
#include  <math.h>
using namespace std;

vector<int> factors;
vector<int> result;
vector<int> temp_result;
int all_sum;

int n, k, p;
void recurse(int sum, int index, int start)
{
	if(sum == n && index == k) 
	{
		int sum = 0;
		for(int i = 0; i < temp_result.size(); ++i)
			sum += temp_result[i];

		if(all_sum == -1 || sum > all_sum)
		{
			result = temp_result;
			all_sum = sum;
		}
		else if(all_sum == sum)
		{
			for(int i = 0; i < k; ++i)
			{
				if(temp_result[i] > result[i])
				{
					result = temp_result;
					break;
				}
				else if(temp_result[i] < result[i])
					break;
			}
		}
	}
	if(sum >= n || index >= k)
		return;
	for(int i = start; i >= 0; --i)
	{
		temp_result.push_back(i + 1);
		recurse(sum + factors[i], index + 1, i);
		temp_result.pop_back();
	}
}

int main()
{
	while(scanf("%d%d%d", &n, &k, &p) != EOF)
	{
		all_sum = -1;
		result.clear();
		temp_result.clear();
		factors.clear();
		for(int i = 1; ; ++i)
		{
			int temp = pow(i, p);
			if(temp <= n)
				factors.push_back(temp);
			else
				break;
			++temp;
		}

		recurse(0, 0, factors.size() - 1);
		if(all_sum == -1)
			printf("Impossible\n");
		else
		{
			printf("%d", n);
			for(int i = 0; i < k; ++i)
				printf("%s%d^%d",i == 0? " = ":" + ", result[i], p);
			printf("\n");
		}
	}
	return 0;
}