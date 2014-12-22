#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	int num;
	while(scanf("%d",&num)!=EOF&&num)
	{
		int flag=0;
		for(int i=2;i<=16;++i)
		{
			int temp=num;
			vector<int> radix_number;
			while(temp)
			{
				radix_number.push_back(temp%i);
				temp/=i;
			}
			int length=radix_number.size();
			int j=0;
			while(j<length-1-j)
			{
				if(radix_number[j]!=radix_number[length-1-j])
					break;
				++j;
			}
			if(j>=length-1-j)
			{
				if(flag==0)
				{
					printf("Number %d is palindrom in basis",num);
					flag=1;
				}
				printf(" %d",i);
			}
		}
		if(!flag)
			printf("Number %d is not a palindrom",num);
		printf("\n");
	}
	return 0;
}