#include  <stdio.h>

int main()
{
	char ch;
	int count=0;
	int first=1;
	while(scanf("%c",&ch)!=EOF)
	{   
		if(ch=='.')
	    {
			if(count!=0)
			{
				if(first)
				   first=0;
			    else
				   printf(" ");
				printf("%d",count);
			}			  
			break;
	    }
		else if(ch==' ')
		{
			if(count!=0)
			{
				if(first)
					first=0;
				else
					printf(" ");
				printf("%d",count);
				count=0;
			}
		}
		else
			++count;
	}
	return 0;
}