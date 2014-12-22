#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <string>
#include  <algorithm>
using namespace std;

void self_inventory(char* dest,char* source)
{
    int tag[10];
    memset(tag,0,sizeof(tag));
    char* p=source;
    char* q=dest;
    while(*p!='\0')
        ++tag[*p++-'0'];
    for(int i=0;i<10;++i)
        if(tag[i]!=0)
        {
            sprintf(q,"%d%d",tag[i],i);
            q+=strlen(q);
        }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            if(i!=0)
                printf("\n");
            char num[90];
            while(scanf("%s",num)!=EOF)
            {
                if(strcmp(num,"-1")==0)
                    break;
                vector<string> traversed;
                traversed.push_back(num);
                printf("%s ",num);
                int k=0;
                while(k<15)
                {
                    char temp[90];
                    self_inventory(temp,num);
                    if(strcmp(temp,num)==0)
                    {
                        if(k==0)
                            printf("is self-inventorying\n");
                        else
                            printf("is self-inventorying after %d steps\n",k);
                        break;
                    }
                    vector<string>::iterator iter=find(traversed.begin(),traversed.end(),temp);
                    if(iter!=traversed.end())
                    {
                        int t=traversed.end()-iter;
                        printf("enters an inventory loop of length %d\n",t);
                        break;
                    }
                    strcpy(num,temp);
                    traversed.push_back(num);
                    ++k;
                }
                if(k>=15)
                    printf("can not be classified after 15 iterations\n");
            }
        }
    }
    return 0;
}
