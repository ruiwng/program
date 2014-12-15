#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int power(int m,int n)
{
	return n==0?1:(m*power(m,n-1));
}
int main()
{	
	int n=0;
	while(scanf("%d",&n)!=EOF)
	{  
	  int count=0;
	  char number[100]={0};
	  sprintf(number,"%d",n);
	  for(unsigned int i=0;i<strlen(number);i++)
	  {
		  int y=n/power(10,strlen(&number[i]));
		  if(number[i]>'1')
		  {
			  count+=(y+1)*power(10,strlen(&number[i])-1);
		  }
		  else if(number[i]=='1')
		  {
			  int x=atoi(&number[i+1])+1;
			  count+=y*power(10,strlen(&number[i])-1)+x;
		  }
		  else if(number[i]=='0')
		  {
			  count+=y*power(10,strlen(&number[i])-1);
		  }
	  }
	  printf("%d\n",count);
	}
	return 0;
}