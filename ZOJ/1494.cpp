#include  <stdio.h>

int main()
{
	int n,u,d;
	while(scanf("%d%d%d",&n,&u,&d)!=EOF&&n)
	{
		int time=0;
		int pos=0;
		while(true)
		{
			++time;
			pos+=u;
			if(pos>=n)
				break;
			++time;
			pos-=d;
		}
		printf("%d\n",time);
	}
	return 0;
}