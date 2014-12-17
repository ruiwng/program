#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;
int main()
{
    int n;
    bool first=true;
    while(scanf("%d",&n)!=EOF)
    {
        if(first)
            first=false;
        else
            printf("\n");
        for(int i=0;i<n;++i)
        {
            int num;
            scanf("%d",&num);
            getchar();
            for(int j=0;j<num;++j)
            {
                char str[5000];
                fgets(str,5000,stdin);
                char* p=str;
                char temp[500];
                bool flag=true;
                while(sscanf(p,"%s",temp)==1)
                {
                    if(flag)
                        flag=false;
                    else
                        printf(" ");
                    reverse(temp,temp+strlen(temp));
                    printf("%s",temp);
                    while(*p==' ')
                        ++p;
                    p=strchr(p,' ');
                    if(p==NULL)
                        break;
                }
                printf("\n");
            }
        }
    }
    return 0;
}
