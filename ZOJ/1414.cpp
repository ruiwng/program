#include  <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x-y==2)
				printf("%d\n",x%2==0?2+(x-2)*2:3+(x-3)*2);
			else if(x==y)
				printf("%d\n",x%2==0?x*2:1+(x-1)*2);
			else
				printf("No Number\n");
		}
	}
	return 0;
}