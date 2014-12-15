#include  <stdio.h>
#include  <string.h>

void transform(char ch[],int num)
{
     for(int i=0;i<2;i++)
	 {
		 int x=num%13;
		 num/=13;
		 if(x>=0&&x<=9)
			 ch[1-i]=x+'0';
		 else
			 ch[1-i]='A'+x-10;
	 }
}

int main()
{
	int a[3];
	while(scanf("%d %d %d",&a[0],&a[1],&a[2])!=EOF)
	{
		char ch[3];
		printf("#");
		for(int i=0;i<3;i++)
		{
		  memset(ch,'\0',3);
		  transform(ch,a[i]);
		  printf("%s",ch);
		}
		printf("\n");
	}
	return 0;
}