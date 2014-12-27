#include  <stdio.h>
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
        int num1;
        if(lhs[i]>='a'&&lhs[i]<='j')
            num1=lhs[i]-'a'+10;
        else
            num1=lhs[i]-'0';
        int num2;
        if(rhs[i]>='a'&&rhs[i]<='j')
            num2=rhs[i]-'a'+10;
        else
            num2=rhs[i]-'0';
        int num=num1+num2+carry;
        if(num>=20)
        {
            num-=20;
            carry=1;
        }
        else
            carry=0;
        if(num<=9)
            lhs[i]=num+'0';
        else
            lhs[i]=num-10+'a';
    }
    if(carry!=0)
        lhs.insert(lhs.begin(),1,'1');
    return lhs;
}

int main()
{
    char str1[110];
    char str2[110];
    while(scanf("%s",str1)!=EOF)
    {
        scanf("%s",str2);
        string result=str_add(str1,str2);
        printf("%s\n",result.c_str());
    }
    return 0;
}
