#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[43];
	while(fgets(str,43,stdin)!=0)
	{
		int length=strlen(str);
		for(int i=0;i<length;++i)
		{
			if(str[i]=='#')
			{
				str[i]='\0';
				break;
			}
			if(str[i]>='a'&&str[i]<='z')
				str[i]=str[i]-'a'+'A';
			else if(str[i]>='A'&&str[i]<='Z')
				str[i]=str[i]-'A'+'a';
		}
		printf("%s",str);
	}
	return 0;
}