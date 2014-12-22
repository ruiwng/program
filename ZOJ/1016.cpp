#include  <stdio.h>
#include  <string.h>

int arry[21];

int main()
{
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		for(int i=0;i<t;++i)
		{
			int n;
			scanf("%d",&n);
			for(int j=0;j<n;++j)
				scanf("%d",&arry[j]);

			char str[50];
			memset(str,0,sizeof(str));
			char *p=str;
			int temp=0;
			for(int j=0;j<n;++j)
			{
				int num=arry[j]-temp;
				while(num--!=0)
					*p++='(';
				*p++=')';
				temp=arry[j];
			}

			p=str;
			bool first=true;
			while(*p!='\0')
			{
				if(*p==')')
				{
					char* q=p;
					int right_parenthesis=0;
					int left_parenthesis=0;
					while(q>=str)
					{
						if(*q==')')
							++right_parenthesis;
						else
						{
							if(++left_parenthesis==right_parenthesis)
								break;
						}
						--q;
					}
					if(first)
						first=false;
					else
						printf(" ");
					printf("%d",right_parenthesis);
				}
				++p;
			}
			printf("\n");
		}
	}
	return 0;
}