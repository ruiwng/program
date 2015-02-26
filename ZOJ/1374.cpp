#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;

char str[100][101];

int main()
{
	int test_cases;
	while(scanf("%d",&test_cases)!=EOF)
	{
		while(test_cases--!=0)
		{
			int n;
			scanf("%d",&n);
			int min_length=120;
			int min_index;
			for(int i=0;i<n;++i)
			{
				scanf("%s",str[i]);
				int len=strlen(str[i]);
				if(len<min_length)
				{
					min_length=len;
					min_index=i;
				}
			}
			int largest=min_length;
			bool success=false;
			while(largest>0)
			{
				for(int i=0;!success&&i<=min_length-largest;++i)
				{
					char temp[120];
					char reverse_temp[120];
					strncpy(temp,&str[min_index][i],largest);
					temp[largest]='\0';
					strcpy(reverse_temp,temp);
					reverse(reverse_temp,reverse_temp+largest);
					int j=0;
					for(;j<n;++j)
					{
						if(!(strstr(str[j],temp)!=NULL||strstr(str[j],reverse_temp)!=NULL))
							break;
					}
					if(j==n)
					{
						success=true;
						break;
					}
				}
				if(success)
					break;
				--largest;
			}
			printf("%d\n",largest);
		}
	}
	return 0;
}
