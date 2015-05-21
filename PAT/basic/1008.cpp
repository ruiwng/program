#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;
int main()
{
	int n1,n2;
	while(scanf("%d %d",&n1,&n2)!=EOF)
	{
		n2%=n1;
		vector<int> intVec;
		intVec.reserve(n1);
		for(int i=0;i<n1;++i)
		{
			int x;
			scanf("%d",&x);
			intVec.push_back(x);
		}
		rotate(intVec.begin(),intVec.begin()+n1-n2,intVec.end());
		for(int i=0;i<n1;++i)
			printf("%d%c",intVec[i],i==n1-1?'\n':' ');
	}
	return 0;
}
