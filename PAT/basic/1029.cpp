#include  <stdio.h>
#include  <string.h>
#include  <ctype.h>

char ascii[256];
int main()
{
    char str1[100];
    char str2[100];
    while(fgets(str1,100,stdin)!=NULL)
    {
        memset(ascii,'\0',sizeof(ascii));
        fgets(str2,100,stdin);
        char *p1=str1;
        char *p2=str2;
        while(*p2!='\n')
            ascii[toupper(*p2++)]=1;
        while(*p1!='\n')
        {
            if(ascii[toupper(*p1)]==0)
            {
                if(*p1=='-')
                    printf(" ");
                else
                    printf("%c",toupper(*p1));
                ascii[toupper(*p1)]=1;
            }
            ++p1;
        }
        printf("\n");
    }
    return 0;
}
