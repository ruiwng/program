#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            if(i!=0)
                printf("\n");
            int line_number;
            scanf("%d",&line_number);
            getchar();
            char source[41000];
            char* p_end=source;
            for(int j=0;j<line_number;++j)
            {
                fgets(p_end,82,stdin);
                p_end=strchr(p_end,'\n');
                *p_end='\0';
            }
            char str[100001];
            char dest[41000];
            char* q_end=dest;
            char* p_start=source;
            memset(dest,0,sizeof(dest));
            while(fgets(str,100001,stdin)!=NULL)
            {
                bool flag=false;
                char* p=str;
                while(*p!='\n')
                {
                    if(*p=='G')
                        *q_end++=*p_start++;
                    else if(*p=='R')
                        reverse(p_start,p_end);
                    else if(*p=='#')
                    {
                        flag=true;
                        break;
                    }
                    ++p;
                }
                if(flag)
                    break;
            }
            printf("%s\n",dest);
        }
    }
    return 0;
}
