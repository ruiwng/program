#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	unsigned int index;
	scanf("%u",&index);
	vector<int> array;
	int temp;
	while(scanf("%d",&temp))
	{
		if(temp<0)
			break;
		else
			array.push_back(temp);
	}
	if(index>array.size())
		printf("NULL\n");
	else
		printf("%d\n",array[array.size()-index]);
	return 0;
}