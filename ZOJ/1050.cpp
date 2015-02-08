#include  <stdio.h>
#include  <ctype.h>
#include  <string.h>
#include  <math.h>
#include  <algorithm>
#include  <map>
#include  <string>
using namespace std;

struct punctuation_func
{
    bool operator()(char c) const
    {
        return !((c>='a'&&c<='z')||(c>='0'&&c<='9')||c==' ');
    }
};

void lower_convert(char *p)//convert uppercase to lowercase
{
    while(*p!='\0')
    {
        *p=tolower(*p);
        ++p;
    }
}

int main()
{
    int input_number;
    while(scanf("%d",&input_number)!=EOF)
    {
        for(int i=0;i<input_number;++i)
        {
            if(i!=0)
                printf("\n");
            map<string,int> search_record;
            char str[260];
            while(fgets(str,260,stdin)!=NULL)
            {
                str[strlen(str)-1]='\0';
                if(strcmp(str,"----------")==0)
                    break;
                lower_convert(str);
                char* q=remove_if(str,str+strlen(str),punctuation_func());
                *q='\0';
                char* p=str;
                while(*p==' ')
                    ++p;
                char temp[50];
                while(sscanf(p,"%s",temp)==1)
                {
                    ++search_record[temp];
                    p=strchr(p,' ');
                    if(p==NULL)
                        break;
                    while(*p==' ')
                        ++p;
                }
            }
            bool flag=true;//tag the end of the input
            map<string,int> current_document;//current document record
            while(fgets(str,260,stdin)!=NULL)
            {
                str[strlen(str)-1]='\0';
                if(strcmp(str,"----------")==0)
                {
                    if(flag)
                        break;
                    else
                    {
                        flag=true;
                        double document_score=0.0;
                        for(map<string,int>::iterator iter=search_record.begin();iter!=search_record.end();++iter)
                            document_score+=sqrt(static_cast<double>(iter->second*current_document[iter->first]));
                        printf("%.2lf\n",document_score);
                        current_document.clear();
                        continue;
                    }
                }
                flag=false;
                lower_convert(str);
               char* q=remove_if(str,str+strlen(str),punctuation_func());
                *q='\0';
                char* p=str;
                while(*p==' ')
                    ++p;
                char temp[50];
                while(sscanf(p,"%s",temp)==1)
                {
                    if(search_record.find(temp)!=search_record.end())
                        ++current_document[temp];
                    p=strchr(p,' ');
                    if(p==NULL)
                        break;
                    while(*p==' ')
                        ++p;
                }
            }
        }
    }
    return 0;
}

