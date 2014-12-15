/*#include  <stdio.h>
#include  <unordered_map>
#include  <string>
#include  <vector>
#include  <string.h>
#include  <algorithm>
#include  <forward_list>
using namespace std;

struct node
{
	forward_list<string> fold;
	forward_list<string> file;
	node():fold(),file(){}
};

void DFS(unordered_map<string,node>& node_info,const string& current_node,unsigned int level)
{
	for(unsigned int i=0;i<level;++i)
		printf("  ");
	size_t temp_pos=current_node.rfind('\\');
	if(temp_pos==string::npos)
	    printf("%s\n",current_node.c_str());
	else
		printf("%s\n",current_node.substr(temp_pos+1).c_str());
	forward_list<string>& fold_temp=node_info[current_node].fold;
    fold_temp.sort();
	fold_temp.unique();
	for(forward_list<string>::const_iterator iter=fold_temp.begin();iter!=fold_temp.end();++iter)
		DFS(node_info,*iter,level+1);
	forward_list<string>& file_temp=node_info[current_node].file;
	file_temp.sort();
	file_temp.unique();
	for(forward_list<string>::const_iterator iter=file_temp.begin();iter!=file_temp.end();++iter)
	{
		for(unsigned int i=0;i<=level;++i)
			printf("  ");
		temp_pos=iter->rfind('\\');
	    if(temp_pos==string::npos)
	        printf("%s\n",iter->c_str());
	    else
		    printf("%s\n",iter->substr(temp_pos+1).c_str());
	}
}

int main()
{
	unsigned int number;
	while(scanf("%u",&number)!=EOF)
	{
		getchar();
		unordered_map<string,node> node_array;
		char temp[300];
		size_t length;
		string current_fold;
		string temp_string;
		string temp_fold;
		string temp_file;
		for(unsigned int i=0;i<number;++i)
		{
			fgets(temp,300,stdin);
			length=strlen(temp);
			if(temp[length-1]=='\n')
				temp[length-1]='\0';

			current_fold="root";
			temp_string=temp;
			size_t pos1=0,pos2=0;
			while(true)
			{
			    pos2=temp_string.find('\\',pos1);
			    if(pos2!=string::npos)
			    {
					temp_fold=temp_string.substr(0,pos2);
					if(node_array.find(temp_fold)==node_array.end())
				         node_array[current_fold].fold.push_front(temp_fold);
					current_fold=temp_fold;
				    pos1=pos2+1;
					if(pos1>=length-1)
						break;
			    }
				else
				{
					temp_file=temp_string;
					node_array[current_fold].file.push_front(temp_file);
					break;
				}
			}
		}
		DFS(node_array,"root",0);
	}
	return 0;
}
*/

#include  <stdio.h>
#include  <unordered_map>
#include  <string>
#include  <forward_list>
#include  <string.h>
#include  <algorithm>
#include  <set>
using namespace std;

struct node
{
	forward_list<string> fold;
	forward_list<string> file;
	node():fold(),file(){}
};

void DFS(unordered_map<string,node>& node_info,const string& current_node,unsigned int level)
{
	for(unsigned int i=0;i<level;++i)
		printf("  ");
	size_t temp_pos=current_node.rfind('\\');
	if(temp_pos==string::npos)
	    printf("%s\n",current_node.c_str());
	else
		printf("%s\n",current_node.substr(temp_pos+1).c_str());
	forward_list<string>& fold_temp=node_info[current_node].fold;
	fold_temp.sort();
	for(forward_list<string>::const_iterator iter=fold_temp.begin();iter!=fold_temp.end();++iter)
		DFS(node_info,*iter,level+1);
	forward_list<string>& file_temp=node_info[current_node].file;
	file_temp.sort();
	for(forward_list<string>::const_iterator iter=file_temp.begin();iter!=file_temp.end();++iter)
	{
		for(unsigned int i=0;i<=level;++i)
			printf("  ");
		temp_pos=iter->rfind('\\');
	    if(temp_pos==string::npos)
	        printf("%s\n",iter->c_str());
	    else
		    printf("%s\n",iter->substr(temp_pos+1).c_str());
	}
}

int main()
{
	unsigned int number;
	while(scanf("%u",&number)!=EOF)
	{
		getchar();
		unordered_map<string,node> node_array;
		char temp[300];
		size_t length;
		string current_fold;
		string temp_string;
		string temp_fold;
		string temp_file;
		for(unsigned int i=0;i<number;++i)
		{
			fgets(temp,300,stdin);
			length=strlen(temp);
			if(temp[length-1]=='\n')
				temp[length-1]='\0';

			current_fold="root";
			temp_string=temp;
			size_t pos1=0,pos2=0;
			while(true)
			{
			    pos2=temp_string.find('\\',pos1);
			    if(pos2!=string::npos)
			    {
					temp_fold=temp_string.substr(0,pos2);
					if(node_array.find(temp_fold)==node_array.end())
				         node_array[current_fold].fold.push_front(temp_fold);
					current_fold=temp_fold;
				    pos1=pos2+1;
					if(pos1>=length-1)
						break;
			    }
				else
				{
					temp_file=temp_string;
					node_array[current_fold].file.push_front(temp_file);
					break;
				}
			}
		}
		DFS(node_array,"root",0);
	}
	return 0;
}
