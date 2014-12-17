#include  <stdio.h>
#include  <vector>
using namespace std;
int main()
{
	unsigned int m,n;
	vector<unsigned int> intVec;
	while(scanf("%u %u",&m,&n)!=EOF)
	{
		while(!intVec.empty())
			intVec.pop_back();
		if(!m)
			intVec.push_back(0);
		while(m!=0)
		{
			intVec.push_back(m%n);
			m/=n;
		}
		vector<unsigned int>::iterator start=intVec.begin();
		vector<unsigned int>::reverse_iterator rstart=intVec.rbegin();
		while(start<=rstart.base()&&(*start==*rstart))
		{
			++start;
			++rstart;
		}
		if(start>=rstart.base())
			printf("Yes\n");
		else
			printf("No\n");
		bool first=true;
		for(vector<unsigned int>::const_reverse_iterator iter=intVec.rbegin();iter!=intVec.rend();++iter)
		{
			if(first)
			   first=false;
			else
				printf(" ");
			printf("%u",*iter);
		}
		printf("\n");
	}
	return 0;
}