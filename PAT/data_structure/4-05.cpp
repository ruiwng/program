#include  <stdio.h>
#include  <string.h>
#include  <string>
#include  <vector>
#include  <stack>
#include  <queue>
#include  <unordered_map>
using namespace std;
struct person
{
	string father_name;
	vector<string> child_array;
	person():father_name(),child_array(){}
};

struct level_info
{
	int level;
	string name;
	level_info():level(0),name(){}
};

bool is_ancestor(unordered_map<string,person>& info,const string& name1,const string& name2)
{
	queue<string> person_queue;
	person_queue.push(name1);
	bool find_success=false;
	while(!person_queue.empty())
	{
		string temp=person_queue.front();
		person_queue.pop();
		vector<string>& children=info[temp].child_array;
		size_t size=children.size();
		for(unsigned int i=0;i<size;++i)
		{
			if(children[i]==name2)
			{
				find_success=true;
				break;
			}
			person_queue.push(children[i]);
		}
		if(find_success)
			break;
	}
	return find_success;
}
int main()
{
	unsigned int name_number,question_number;
	while(scanf("%u %u",&name_number,&question_number)!=EOF)
	{
		unordered_map<string,person> info_array;
		stack<level_info> level_stack;
		getchar();
		for(unsigned int i=0;i<name_number;++i)
		{
			char temp[75];
			fgets(temp,75,stdin);
			int length=strlen(temp);
			if(temp[length-1]=='\n')
				temp[length-1]='\0';
			length--;
			int space_count=0;
			unsigned int j=0;
			while(temp[j]==' ')
			{
				++space_count;
				++j;
			}
			level_info level_temp;
			level_temp.level=space_count;
			level_temp.name=&temp[j];
			while(!level_stack.empty()&&level_stack.top().level>=level_temp.level)
				level_stack.pop();
			if(!level_stack.empty())
			{
				info_array[level_temp.name].father_name=level_stack.top().name;
				info_array[level_stack.top().name].child_array.push_back(level_temp.name);
			}
			else
			    info_array.insert(make_pair(level_temp.name,person()));
			level_stack.push(level_temp);
		}
		for(unsigned int i=0;i<question_number;++i)
		{
			char temp[75];
			fgets(temp,75,stdin);
			int length=strlen(temp);
			if(temp[length-1]=='\n')
				temp[length-1]='\0';
			string temp_str=temp;
			size_t pos1=0;
			pos1=temp_str.find(' ',pos1);
			string name1=temp_str.substr(0,pos1);
			++pos1;
			pos1=temp_str.find(' ',pos1);
			++pos1;
			pos1=temp_str.find(' ',pos1);
			++pos1;
			int current_pos=pos1;
			pos1=temp_str.find(' ',pos1);
			string relationship=temp_str.substr(current_pos,pos1-current_pos);
			pos1=temp_str.rfind(' ');
			string name2=temp_str.substr(pos1+1);

			if(relationship=="child")
			{
				if(info_array[name1].father_name==name2)
					printf("True\n");
				else
					printf("False\n");
			}
			else if(relationship=="parent")
			{
				if(info_array[name2].father_name==name1)
					printf("True\n");
				else
					printf("False\n");
			}
			else if(relationship=="sibling")
			{
				if(info_array[name1].father_name==info_array[name2].father_name)
					printf("True\n");
				else
					printf("False\n");
			}
			else if(relationship=="descendant")
			{
				if(is_ancestor(info_array,name2,name1))
					printf("True\n");
				else
					printf("False\n");
			}
			else if(relationship=="ancestor")
			{
				if(is_ancestor(info_array,name1,name2))
					printf("True\n");
				else
					printf("False\n");
			}
		}
	}
	return 0;
}



