#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <string>
#include  <algorithm>
using namespace std;

int duplicates[2001];
vector<string> dictionary;
char phrase[1000];
string comp(26,'0');

bool is_rational(string& s,int index)
{
    string temp=dictionary[index];
    for(int i=0;i<temp.size();++i)
    {
         if(s[temp[i]-'A']=='0')
            return false;
         else
             --s[temp[i]-'A'];
    }
    return true;
}

void func(vector<int> info,string s,int index)
{
    if(s==comp)
    {
        printf("%s =",phrase);
        int len=info.size();
        for(int i=0;i<len;++i)
            printf(" %s",dictionary[info[i]].c_str());
        printf("\n");
		return;
    }
    if(index>=dictionary.size())
        return;  
	string temp(s);
    if(duplicates[index]!=1&&is_rational(temp,index))
    {
		vector<int> info_temp(info);
        info_temp.push_back(index);
        func(info_temp,temp,index+1);
    }
	func(info,s,index+1);
}

int main()
{
    char str[30];
    while(scanf("%s",str)!=EOF)
    {
        if(str[0]=='#')
            break;
        dictionary.push_back(str);
    }
    fgets(str,30,stdin);
    while(fgets(phrase,1000,stdin)!=NULL)
    {
        if(phrase[1]=='\n'&&phrase[0]=='#')
            break;
        phrase[strlen(phrase)-1]='\0';
        char* p=phrase;
        while(*p==' ')
            ++p;
        string letter_records(26,'0');
        memset(duplicates,0,sizeof(duplicates));
        char temp[30];
        while(sscanf(p,"%s",temp)==1)
        {
            vector<string>::iterator iter=lower_bound(dictionary.begin(),dictionary.end(),temp);
            if(iter!=dictionary.end()&&*iter==temp)
                duplicates[iter-dictionary.begin()]=1;
            char* q=temp;
            while(*q!='\0')
                ++letter_records[*q++-'A'];
            p=strchr(p,' ');
            if(p==NULL)
                break;
            while(*p==' ')
                ++p;
        }
        func(vector<int>(),letter_records,0);
    }
    
    return 0;
}
