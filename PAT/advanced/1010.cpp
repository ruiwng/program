#include  <stdio.h>
#include  <string.h>
#include  <string>
using namespace std;
int main()
{
	char ch[2][11];
	unsigned long long num,radix;

	while(scanf("%s %s %llu %llu",ch[0],ch[1],&num,&radix)!=EOF)
	{
		string str1=ch[0];
		string str2=ch[1];

		if(num==2)
			str1.swap(str2);
		int n=str1.length();
		unsigned long long number=0;
		for(int i=0;i<n;i++)
		{
			if(str1[i]>='0'&&str1[i]<='9')
			   number=number*radix+str1[i]-'0';
			else
			   number=number*radix+str1[i]-'a'+10;
		}
	    char y='0';
		n=str2.length();
		for(int i=0;i<n;i++)
		{
			if(str2[i]>y)
				y=str2[i];
		}
		if(y>='0'&&y<='9')
			radix=y-'0'+1;
		else 
			radix=y-'a'+11;
		unsigned long long number2;
		unsigned long long low=radix,high=number;
		if(str2.length()==1)
		{
			if(str2[0]>='0'&&str2[0]<='9')
				number2=str2[0]-'0';
			else
				number2=str2[0]-'a'+10;
		}
		else
		while(low<=high)
		{
			radix=(low+high)/2;
			number2=0;
			for(int i=0;i<n;i++)
		    {
			if(str2[i]>='0'&&str2[i]<='9')
			   number2=number2*radix+str2[i]-'0';
			else
			   number2=number2*radix+str2[i]-'a'+10;
		    }
			if(number2<number)
				low=radix+1;
			else if(number2>number)
				high=radix-1;
			else
				break;
		}
		if(number2==number)
			printf("%d\n",radix);
		else
			printf("Impossible\n");
	}
	return 0;
}
