#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <algorithm>
using namespace std;
char DAY[7][4]=
{
	"MON",
	"TUE",
	"WED",
	"THU",
	"FRI",
	"SAT",
	"SUN"
};

int main()
{
	char ch[4][62];
	char ch1[2];
	for(int i=0;i<4;i++)
	{
	 fgets(ch[i],62,stdin);
	}
        int n1=strlen(ch[0]);
	int n2=strlen(ch[1]);
	n1=min(n1,n2);
	int count=0;
	for(int i=0;i<n1;i++)
	{
		if(count==0)
		{
		   if(ch[0][i]==ch[1][i]&&ch[0][i]>='A'&&ch[0][i]<='G')
			  ch1[count++]=ch[0][i];
		}
		else
		{
			if(ch[0][i]==ch[1][i]&&((ch[0][i]>='A'&&ch[0][i]<='N')||(ch[0][i]>='0'&&ch[0][i]<='9')))
			{
				ch1[count++]=ch[0][i];
				break;
			}
		}
	}
	n1=strlen(ch[2]);
	n2=strlen(ch[3]);
	n1=min(n1,n2);
	int cnt=-1;
	for(int i=0;i<n1;i++)
	{
		cnt++;
		if(ch[2][i]==ch[3][i]&&((ch[2][i]>='A'&&ch[2][i]<='Z')||(ch[2][i]>='a'&&ch[2][i]<='z')))
		    break;
	}
	printf("%s %02d:%02d\n",DAY[ch1[0]-'A'],(ch1[1]>='0'&&ch1[1]<='9')?(ch1[1]-'0'):(10+ch1[1]-'A'),cnt);
	return 0;
}