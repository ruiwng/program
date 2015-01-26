#include  <stdio.h>
#include  <math.h>
#include  <vector>
using namespace std;

bool is_primer(int n)
{
	if(n==1)
		return false;
	int temp=sqrt(static_cast<double>(n));
	for(int j=2;j<=temp;++j)
	{
		if(n%j==0)
			return false;
	}
	return true;
}

int main()
{
	int m_size,input;
	while(scanf("%d%d",&m_size,&input)!=EOF)
	{
		while(!is_primer(m_size))
			++m_size;
		vector<int> tags(m_size,0);
		for(int i=0;i<input;++i)
		{
			int k;
			scanf("%d",&k);
			int j=0;
			for(;j<=m_size;++j)
			{
				int t=(k+j*j)%m_size;
                if(tags[t]==0)
				{
					printf("%d",t);
					tags[t]=1;
					break;
				}
			}
			if(j>m_size)
				printf("-");
			printf("%c",i==input-1?'\n':' ');
		}
	}
	return 0;
}