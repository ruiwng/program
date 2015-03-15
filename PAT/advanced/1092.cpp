#include  <stdio.h>
#include  <string.h>

int main()
{
	char str1[1010],str2[1010];
	while(scanf("%s%s",str1,str2)!=EOF)
	{
		int tags[200];
		memset(tags,0,sizeof(tags));
		char *p=str2;
		while(*p!='\0')
			++tags[static_cast<int>(*p++)];
		p=str1;
		while(*p!='\0')
			--tags[static_cast<int>(*p++)];
		int extra=0,missing=0;
		bool flag=true;
		for(int i=0;i<200;++i)
		{
			if(tags[i]>0)
			{
				flag=false;
				missing+=tags[i];
			}
			else
				extra-=tags[i];
		}
		if(flag)
			printf("Yes %d\n",extra);
		else
			printf("No %d\n",missing);
	}
	return 0;
}
