#include  <stdio.h>

int main()
{
	char str[5];
	while(scanf("%s",str)!=EOF)
	{
		for(unsigned int i=0;i<4;++i)
			str[i]=(str[i]-'0'+9)%10+'0';

	    char temp=str[0];
		str[0]=str[2];
		str[2]=temp;
		temp=str[1];
		str[1]=str[3];
		str[3]=temp;
		printf("The encrypted number is %s\n",str);
	}
	return 0;
}