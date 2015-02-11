#include  <stdio.h>
#include  <string.h>
#include  <string>
#include  <vector>
#include  <algorithm>
using namespace std;

char str[300];

struct comp_func
{
    bool operator()(const string& lhs,const string& rhs) const
    {
        return lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end());
    }
};

void func(vector<string>& result_array,string s,char* p)
{
    while(*p!='\0'&&*p!='[')
        s.push_back(*p++);
    if(*p=='\0')
        result_array.push_back(s);
    else if(*p=='[')
    {
        char* q=p;
        char* k=p;
        int l=0;
        int r=0;
        while(true)
        {
            if(*k=='[')
                ++l;
            else if(*k==']')
            {
                ++r;
                if(r==l)
                    break;
            }
            ++k;
        }
        ++k;
        while(true)
        {
            ++q;
            char m[300];
            memset(m,0,sizeof(m));
            int index=0;
            int left=0;
            int right=0;
            while(true)
            {
                if(*q=='[')
                    ++left;
                else if(*q==']')
                {
                    ++right;
                    if(right-left==1)
                        break;
                }
                else if(*q=='|')
                {
                    if(left==right)
                        break;
                }
                m[index++]=*q++;
            }
            vector<string> t;
            func(t,string(),m);
            int len=t.size();
            for(int i=0;i<len;++i)
            {
                string temp(s);
                temp.append(t[i]);
                func(result_array,temp,k);
            }            
            p=q;
            if(*q==']')
                break;
        }
    }
}

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        fgets(str,300,stdin);
        for(int i=0;i<N;++i)
        {
            fgets(str,300,stdin);
            if(i!=0)
                printf("\n");
            fgets(str,300,stdin);
            str[strlen(str)-1]='\0';
            vector<string> record_array;
            func(record_array,string(),str);
            sort(record_array.begin(),record_array.end(),comp_func());
            record_array.erase(unique(record_array.begin(),record_array.end()),record_array.end());
            int len=record_array.size();
            for(int i=0;i<len;++i)
                printf("%s\n",record_array[i].c_str());           
        }
    }
    return 0;
}
