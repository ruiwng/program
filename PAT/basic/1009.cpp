#include  <stdio.h>
#include  <string.h>

int main()
{
	 char ch[82];
	 while(fgets(ch,82,stdin)!=NULL)
	 {
		 int n=strlen(ch);
		 if(ch[n-1]=='\n')
			 ch[n-1]='\0';
		 char* p=ch+n;
		 while(true)
		 {
			while(*p!=' '&&p>=ch)
			  --p;
			printf("%s",p+1);
			if(p<ch)
				break;
			else    
			{
				*p--='\0';
				printf(" ");
			}
		 }
		 printf("\n");
	 }
	 return 0;
}
