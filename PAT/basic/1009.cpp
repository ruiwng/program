#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
int main()
{
	 char ch[82];
	 while(fgets(ch,82,stdin))
	 {
		 int n=strlen(ch);
		 if(ch[n-1]=='\n')
			 ch[n-1]='\0';
		 char* p;
		 while((p=strrchr(ch,' ')))
		 {
			 printf("%s ",p+1);
			 *p='\0';
		 }
		 printf("%s\n",ch);
	 }
	 return 0;
}