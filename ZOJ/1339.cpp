#include  <stdio.h>
#include  <string.h>

int main()
{
	int n;
	while(scanf("%d\n",&n)!=EOF&&n)
	{
		char str[30];    
		int sum=0;
		int min_num=30;
		for(int i=0;i<n;++i)
		{
			fgets(str,30,stdin);
			char *p=str;
			int current_num=0;
			p=strchr(p,' ');
			if(p!=NULL)
			{
				while(*p++==' ')
					++current_num;
			}
			if(current_num<min_num)
				min_num=current_num;
			sum+=current_num;
		}
		printf("%d\n",sum-n*min_num);
	}
	return 0;
}