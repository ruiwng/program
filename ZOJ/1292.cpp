#include  <stdio.h>
#include  <string.h>
#include  <string>
using namespace std;

string str_add(string lhs,string rhs)
{
    int len1=lhs.size();
    int len2=rhs.size();
    if(len1<len2)
    {
        lhs.swap(rhs);
        len1=lhs.size();
        len2=rhs.size();
    }
    rhs.insert(rhs.begin(),len1-len2,'0');
    int carry=0;
    for(int i=len1-1;i>=0;--i)
    {
        int temp=lhs[i]-'0'+rhs[i]-'0'+carry;
        if(temp>=10)
        {
            temp-=10;
            carry=1;
        }
        else
            carry=0;
        lhs[i]=temp+'0';
    }
    if(carry!=0)
        lhs.insert(lhs.begin(),1,'1');
    return lhs;
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
            string result("0");
            char str[110];
            while(scanf("%s",str))
            {
                if(strcmp(str,"0")==0)
                    break;
                result=str_add(result,str);
            }
            printf("%s\n",result.c_str());
        }
    }
    return 0;
}
