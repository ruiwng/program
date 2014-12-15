#include  <stdio.h>
#include  <stdlib.h>
#include  <vector>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		vector<int> intVec;
		for(int i=0;i<n;i++)
		{
			long long a,b,c;
			scanf("%lld %lld %lld",&a,&b,&c);
			if(a+b>c)
				intVec.push_back(1);
			else
				intVec.push_back(0);
		}
		for(unsigned int i=0;i<intVec.size();++i)
		{
			if(intVec[i]==1)
				printf("Case #%d: true\n",i+1);
			else
				printf("Case #%d: false\n",i+1);
		}
	}
	return 0;
}