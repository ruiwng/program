#include  <stdio.h>
#include  <vector>
#include  <algorithm>

using namespace std;

int main()
{
	vector<int> array(3);
	while(scanf("%d %d %d",&array[0],&array[1],&array[2])!=EOF)
	{
		sort(array.begin(),array.end());
		printf("%d->%d->%d\n",array[0],array[1],array[2]);
	}
	return 0;
}