#include  <stdio.h>

int q[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char s[11]={'1','0','X','9','8','7','6','5','4','3','2'};
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int rational=1;
		char str[20];
		for(int i=0;i<n;++i)
		{
			scanf("%s",str);
			int sum=0;
			int error=0;
			for(int j=0;j<17;++j)
			{
				if(str[j]>='0'&&str[j]<='9')
					sum+=(str[j]-'0')*q[j];
				else
				{
					rational=0;
					error=1;
					printf("%s\n",str);
					break;
				}
			}
			if(!error)
			{
				sum%=11;
			    if(s[sum]!=str[17])
			    {
				  rational=0;
				  printf("%s\n",str);
			    }
			}			
		}
		if(rational)
			printf("All passed\n");
	}
}

