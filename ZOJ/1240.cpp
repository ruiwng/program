#include  <stdio.h>

int main()
{
  int string_number=0;
  while(scanf("%d",&string_number)!=EOF)
  {
    for(int i=0;i<string_number;++i)
    {
      char str[60];
      scanf("%s",str);
      char *p=str;
      printf("String #%d\n",i+1);
      while(*p!='\0')
      {
	printf("%c",*p=='Z'?'A':*p+1);
	++p;
      }
      printf("\n\n");
    }
  }
  return 0;
}
