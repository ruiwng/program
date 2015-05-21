#include  <stdio.h>
#include  <string.h>

const char* number[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main()
{
	char ch[110];
	while(scanf("%s",ch)!=EOF)
	{
            int sum=0;
            char *p=ch;
	    while(*p!='\0')		
     	       sum+=*p++-'0';
	    char temp[5];
	    sprintf(temp,"%d",sum);
	    p=temp;
            while(true)
	    {
		printf("%s",number[*p++-'0']);
                if(*p=='\0')
		{
			printf("\n");
			break;
		}
		else
		        printf(" ");
	    }
	}
	return 0;
}
