#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[30];
	while(scanf("%s",str)!=EOF)
	{
	     int tag[10];
		 memset(tag,0,sizeof(tag));
		 char *p=str;
		 while(*p!='\0')
			 ++tag[*p++-'0'];
		 --p;
		 int carry=0;
		 while(p>=str)
		 {
			int temp=(*p-'0')*2+carry;
			carry=temp/10;
			temp=temp%10;
			*p--=temp+'0';
		 }
		 if(carry!=0)
		 {
			 printf("No\n");
			 printf("%d%s\n",carry,str);
		 }
		 else
		 {
			 p=str;
			 while(*p!='\0')
				 --tag[*p++-'0'];
			 int k;
			 for(k=0;k<10;++k)
				 if(tag[k]!=0)
					 break;
			 if(k==10)
				 printf("Yes\n");
			 else
				 printf("No\n");
			 printf("%s\n",str);
		 }
	}
	return 0;
}