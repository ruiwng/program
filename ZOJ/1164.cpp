#include  <stdio.h>

int main()
{
    char str[1100];
    while(fgets(str,1100,stdin)!=NULL)
    {
        if(str[1]=='\n'&&str[0]=='#')
            break;
        char* p=str;
        int remainder=0;
        while(*p!='\n')
        {
            remainder=remainder*256+*p++;
            remainder%=34943;
        }
        remainder*=256;
        remainder%=34943;
        remainder*=256;
        remainder%=34943;
        int t=34943-remainder%34943;
        if(t==34943)
            t=0;
        printf("%02X %02X\n",t/256,t%256);
    }
    return 0;
}
