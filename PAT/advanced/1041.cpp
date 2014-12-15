#include  <stdio.h>
#include  <vector>
using namespace std;
int array[10001];
int main()
{
	int n;
	vector<int> intVec;
	while(scanf("%d",&n)!=EOF)
	{
		while(!intVec.empty())
			intVec.pop_back();
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			array[temp]++;
			intVec.push_back(temp);
		}
		vector<int>::const_iterator iter;
		for(iter=intVec.begin();iter!=intVec.end();++iter)
		{
			if(array[*iter]==1)
			{
				printf("%d\n",*iter);
				break;
			}
		}
		if(iter==intVec.end())
			printf("None\n");
	}
	return 0;
}