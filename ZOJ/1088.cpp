#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		vector<int> vec;
		for(int i=1;i<=n;++i)
			vec.push_back(i);
		for(int i=2;;++i)
		{
			vector<int> temp=vec;
			int pos=0;
			while(temp.size()!=1)
			{
				temp.erase(temp.begin()+pos);
				pos=(pos+i-1)%temp.size();
			}
			if(temp[0]==2)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}