#include  <stdio.h>
#include  <stdlib.h>
#include  <vector>
#include  <iterator>
#include  <algorithm>
using namespace std;
int main()
{
	int n1,n2;
	while(scanf("%d %d",&n1,&n2)!=EOF)
	{
		n2%=n1;
		vector<int> intVec;
		for(int i=0;i<n1;i++)
		{
			int x;
			scanf("%d",&x);
			intVec.push_back(x);
		}
		reverse(intVec.begin(),intVec.end()-n2);
		reverse(intVec.end()-n2,intVec.end());
		reverse(intVec.begin(),intVec.end());
		for(vector<int>::const_iterator it=intVec.begin();it<intVec.end();it++)
		{
			printf("%d",*it);
			if(it!=(intVec.end()-1))
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}