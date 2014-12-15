#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <algorithm>
using namespace std;

void exchange(char& c1,char& c2)
{
	char temp;
	temp=c1;
	c1=c2;
	c2=temp;
}

int main()
{
	char ch[5];
	while(scanf("%s",ch)!=EOF)
	{
		int n=strlen(ch);
		if(n<4)
		{
			ch[4]='\0';
			for(int i=0;i<n;i++)
			   ch[3-i]=ch[n-i-1];
			for(int i=0;i<4-n;i++)
			   ch[i]='0';
		}
		if(ch[0]==ch[1]&&ch[1]==ch[2]&&ch[2]==ch[3])
			printf("%s - %s = 0000\n",ch,ch);
		else
		do
		{
			int num1,num2,num3;
			sort(ch,ch+4);
			num1=atoi(ch);
			exchange(ch[0],ch[3]);
			exchange(ch[1],ch[2]);
			num2=atoi(ch);
			num3=num2-num1;
			printf("%04d - %04d = %04d\n",num2,num1,num3);
			if(num3==6174)
				break;
			sprintf(ch,"%04d",num3);
		}while(true);
	}
	return 0;
}