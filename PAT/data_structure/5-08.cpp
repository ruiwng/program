
#include  <stdio.h>
#include  <string.h>
#include  <string>
#include  <unordered_map>
#include  <vector>
#include  <set>
#include  <map>
#include  <algorithm>
using namespace std;

struct file_info
{
	string topic_name;//the topic of the file 
	vector<string> file_description;//descriptions of the file
	unordered_map<string,vector<unsigned int> > keyword_index;//the keywords of the file to descriptions
	file_info():topic_name(),file_description(),keyword_index(){}
};

int main()
{
	unsigned int number_file;
	while(scanf("%u",&number_file)!=EOF)
	{
		vector<file_info> info_array(number_file);// all files' information
		char topic[60];
		unsigned int file_index=0;//current file index 
		unordered_map<string,vector<unsigned int> > keyword_array;//all the keywords index to the position of all files 
		getchar();
		while(true)//get the information of the current file
		{
			fgets(topic,60,stdin);
			unsigned int length=strlen(topic);//get the topic of the file
			topic[length-1]='\0';
			info_array[file_index].topic_name=topic;
			char temp[60];
			unsigned int description_index=0;
			while(true)//get the description of current file
			{
				fgets(temp,60,stdin);
				length=strlen(temp);
				temp[length-1]='\0';
				if(strcmp(temp,"#")==0)
					break;
				info_array[file_index].file_description.push_back(temp);
				for(unsigned int i=0;i<length-1;++i)
				   temp[i]=tolower(temp[i]);
				char *p=temp;
				while(true)//get the keyword of the current description
				{
					char* q=strchr(p,' ');
					if(q!=NULL)
						*q='\0';
					vector<unsigned int>& file_temp=keyword_array[p];
					if(!(!file_temp.empty()&&file_temp.back()==file_index))
					      file_temp.push_back(file_index);//map the keyword to the position of the current file
					vector<unsigned int>& description_temp=info_array[file_index].keyword_index[p];
					if(!(!description_temp.empty()&&description_temp.back()==description_index))
					     description_temp.push_back(description_index);//inser pair of keyword and the relevant descrption 
					if(q==NULL)
						break;
					else
					{
						++q;
						while(*q==' ')
							++q;
					}
					p=q;
				}
				++description_index;
			}
			if(++file_index==number_file)
				break;
		}
		unsigned int query_number;
		scanf("%u",&query_number);
		getchar();
		for(unsigned int i=0;i<query_number;++i)
		{
			char temp[60];
			fgets(temp,60,stdin);
			unsigned int length=strlen(temp);//get current query information
			temp[length-1]='\0';
			for(unsigned int i=0;i<length-1;++i)
				   temp[i]=tolower(temp[i]);
			char *p=temp;
			vector<string> keyword_temp;
			while(true)//get all the keywords of the current description, and push them into the keyword_temp
			{
				char* q=strchr(p,' ');
				if(q!=NULL)
					*q='\0';
				keyword_temp.push_back(p);
				if(q==NULL)
					break;
				else
				{
					++q;
					while(*q==' ')
						++q;
				}
					p=q;
			}
		    
			vector<unsigned int> result;
			bool first=true;
			for(unsigned int j=0;j<keyword_temp.size();++j)//traverse the keywords, and get the intersection of them.
			{
				unordered_map<string,vector<unsigned int> >::iterator iter=keyword_array.find(keyword_temp[j]);
				if(iter!=keyword_array.end())
				{
					if(first)
					{
						first=false;
						result=iter->second;
					}
					else
					{
						vector<unsigned int> temp;
						set_intersection(result.begin(),result.end(),iter->second.begin(),iter->second.end(),
							back_inserter(temp));
						result.swap(temp);
						if(result.empty())
							break;
					}
				}
				else
				{
					result.clear();
					break;
				}
			}
			printf("%u\n",result.size());
			if(result.empty())
				printf("Not Found\n");
			else
			{
				for(unsigned int j=0;j<result.size();++j)
				{
					printf("%s\n",info_array[result[j]].topic_name.c_str());
					vector<unsigned int> query_info;
					for(vector<string>::iterator iter_temp=keyword_temp.begin();iter_temp!=keyword_temp.end();++iter_temp)
					{
						vector<unsigned int>& description_temp=info_array[result[j]].keyword_index[*iter_temp];
						vector<unsigned int> temp;
						set_union(query_info.begin(),query_info.end(),description_temp.begin(),description_temp.end(),
							back_inserter(temp));
						query_info.swap(temp);
					}
					for(unsigned int k=0;k<query_info.size();++k)
						printf("%s\n",info_array[result[j]].file_description[query_info[k]].c_str());
				}

			}
		}
	}
	return 0;
}


