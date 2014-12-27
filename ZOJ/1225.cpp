#include  <stdio.h>
#include  <ctype.h>
#include  <string.h>
#include  <vector>
#include  <string>
#include  <algorithm>
using namespace std;

struct char_comp
{
    bool operator()(char lhs,char rhs)
    {
        return tolower(lhs)<tolower(rhs);
    }
};
struct comp_func
{
    bool operator()(const string& lhs,const string& rhs) const
    {
        return lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end(),char_comp());
    }
};

int main()
{
    char str[1000];
    while(fgets(str,1000,stdin)!=NULL)
    {
        int len=strlen(str);
        if(str[len-1]=='\n')
            str[len-1]='\0';
        if(strcmp(str,".")==0)
            break;
        char* p=str;
        while(*p==' ')
            ++p;
        vector<int> number_array;
        vector<string> str_array;
        vector<int> record;
        while(true)
        {
            if((*p>='0'&&*p<='9')||*p=='+'||*p=='-')
            {
                int temp;
                sscanf(p,"%d",&temp);
                number_array.push_back(temp);
                record.push_back(0);
            }
            else
            {
                char temp[100];
                sscanf(p,"%s",temp);
                int len=strlen(temp);
                if(temp[len-1]==','||temp[len-1]=='.')
                    temp[len-1]='\0';
                str_array.push_back(temp);
                record.push_back(1);
            }
            p=strchr(p,' ');
            if(p==NULL)
                break;
            ++p;
        }
        sort(number_array.begin(),number_array.end());
        sort(str_array.begin(),str_array.end(),comp_func());
        int index1=0,index2=0;
        int record_len=record.size();
        for(int i=0;i<record_len;++i)
        {
            if(record[i]==0)
                printf("%d%s",number_array[index1++],i==record_len-1?".\n":", ");
            else
                printf("%s%s",str_array[index2++].c_str(),i==record_len-1?".\n":", ");
        }
    }
    return 0;
}
