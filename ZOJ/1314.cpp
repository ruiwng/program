#include  <stdio.h>
#include  <string.h>

char tag[100000];

int main()
{
	int step,mod;
	while(scanf("%d%d",&step,&mod)!=EOF)
	{
		memset(tag,0,sizeof(tag));
		int seed=0;
		tag[seed]=1;
		int num=1;
		while(1)
		{
			seed=(seed+step)%mod;
			if(tag[seed]==1)
				break;
			else
			{
				tag[seed]=1;
				++num;
			}
		}
		printf("%10d%10d    %s\n\n",step,mod,num==mod?"Good Choice":"Bad Choice");
	}
	return 0;
}