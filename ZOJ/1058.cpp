#include  <stdio.h>

double currency_info[6][6];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			if(i>0)
				printf("\n");
			for(int j=1;j<=5;++j)
				for(int k=1;k<=5;++k)
					scanf("%lf",&currency_info[j][k]);

			int num;
			while(scanf("%d",&num)!=EOF&&num)
			{
				int arry[11];
				arry[0]=1;
				arry[num+1]=1;
				for(int j=1;j<=num;++j)
					scanf("%d",&arry[j]);
				double current_value;
				scanf("%lf",&current_value);
				for(int j=0;j<=num;++j)
				{
					current_value=current_value*currency_info[arry[j]][arry[j+1]];
					char str[20];
					sprintf(str,"%.2lf",current_value);
					sscanf(str,"%lf",&current_value);
				}
				printf("%.2lf\n",current_value);
			}
		}
	}
	return 0;
}