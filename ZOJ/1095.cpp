#include  <stdio.h>
#include  <string.h>

int arry[5841];

int main()
{
	arry[0]=1;
	int index2=0;
	int index3=0;
	int index5=0;
	int index7=0;
	int i=1;
	while(i<=5841)
	{
		int temp2=arry[index2]*2;
		int temp3=arry[index3]*3;
		int temp5=arry[index5]*5;
		int temp7=arry[index7]*7;
		if(temp2<=temp3&&temp2<=temp5&&temp2<=temp7)
		{
			if(arry[i-1]<temp2)
				arry[i++]=temp2;
			++index2;
		}
		else if(temp3<=temp2&&temp3<=temp5&&temp3<=temp7)
		{
			if(arry[i-1]<temp3)
			   arry[i++]=temp3;
			++index3;
		}
		else if(temp5<=temp2&&temp5<=temp3&&temp5<=temp7)
		{
			if(arry[i-1]<temp5)
				arry[i++]=temp5;
			++index5;
		}
		else 
		{
			if(arry[i-1]<temp7)
				arry[i++]=temp7;
			++index7;
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		char str[3];
	    if(n%10==1&&n%100!=11)
			strcpy(str,"st");
		else if(n%10==2&&n%100!=12)
			strcpy(str,"nd");
		else if(n%10==3&&n%100!=13)
			strcpy(str,"rd");
		else
			strcpy(str,"th");
		printf("The %d%s humble number is %d.\n",n,str,arry[n-1]);
	}
	return 0;
}