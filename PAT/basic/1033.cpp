#include  <stdio.h>
#include  <string.h>

int arr[260];

int main()
{
	char str1[100010],str2[100010];
	while(fgets(str1,100010,stdin)!=NULL)
	{
		fgets(str2,100010,stdin);
		memset(arr,0,sizeof(arr));
		char *p=str1;
		while(*p!='\n')
		{
			arr[*p]=1;
			if(*p>='A'&&*p<='Z')
				arr[*p-'A'+'a']=1;
			++p;
		}

	    p=str2;
		while(*p!='\n')
		{
			if(!arr[*p])
			{
				if(!(*p>='A'&&*p<='Z'&&arr['+']==1))
					printf("%c",*p);
			}
			++p;
		}
		printf("\n");
	}
	return 0;
}
