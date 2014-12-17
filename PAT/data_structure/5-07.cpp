#include  <stdio.h>
#include  <string.h>
#include  <map>
#include  <string>
#include  <algorithm>
using namespace std;

int main()
{
	unsigned int record;
	while(scanf("%u",&record)!=EOF)
	{
		char str[150];
		getchar();
		map<string,unsigned int> record_info;
		unsigned int max_count=0;
		for(unsigned int i=0;i<record;++i)
		{
			fgets(str,150,stdin);
			unsigned int length=strlen(str);
			if(str[length-1]=='\n')
				str[length-1]='\0';
			string temp=str;
			size_t pos1=temp.find('#');
			size_t pos2;
			while(pos1!=string::npos)
			{
				pos2=temp.find('#',pos1+1);
				string topic=temp.substr(pos1+1,pos2-pos1-1);
				if(topic.length()>40)
					topic.erase(40);
				for(unsigned int j=0;j<topic.size();++j)
				{
					if(isalnum(topic[j])||topic[j]=='!'||topic[j]=='?')
						continue;
					topic[j]=' ';
				}
				while(topic.back()==' ')
					topic.pop_back();
				string str1=topic;
				topic.front()=toupper(topic.front());
				unsigned int temp_count=++record_info[topic];
				if(temp_count>max_count)
					 max_count=temp_count;

				pos1=temp.find('#',pos2+1);
			}
		}
		bool first=true;
		unsigned int number=0;
		for(map<string,unsigned int>::iterator iter=record_info.begin();iter!=record_info.end();++iter)
		{
			if(iter->second==max_count)
			{
				if(first)
				{
					first=false;
					printf("%s\n",iter->first.c_str());
					printf("%u\n",max_count);
					first=false;
				}
				else
				    ++number;
			}
		}
		if(number!=0)
			printf("And %u more ...\n",number);
	}
	return 0;
}
