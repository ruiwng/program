#include <stdio.h>
#include <vector>
using namespace std;
int main()
{
	int n;
	vector<int> intVec,intVec2;
	while(scanf("%d",&n)!=EOF)
	{
		while(!intVec.empty())
			intVec.pop_back();
		while(!intVec2.empty())
			intVec2.pop_back();
		int sum=0;
		intVec.push_back(0);
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			sum+=temp;
			if(i!=n-1)
			   intVec.push_back(sum);		
		}
		int number;
		scanf("%d",&number);
		for(int i=0;i<number;i++)
		{
			int begin,end;
			scanf("%d %d",&begin,&end);
			int temp1,temp2;
			int distance1=0,distance2=0;
			if(begin<end)
				distance1=intVec[end-1]-intVec[begin-1];
			else
				distance1=intVec[begin-1]-intVec[end-1];
			distance2=sum-distance1;
			int distance;
			if(distance1<=distance2)
				intVec2.push_back(distance1);
			else
				intVec2.push_back(distance2);
		}
		for(vector<int>::const_iterator iter=intVec2.begin();iter!=intVec2.end();iter++)
		   printf("%d\n",*iter);

	}
	return 0;
}