/*
#include  <stdio.h>
#include  <unordered_map>
#include  <string>
using namespace std;

int main()
{
	unsigned int number_command;
	while(scanf("%u",&number_command)!=EOF)
	{
		unordered_map<unsigned int,string> user_info;
		char command[2];
		unsigned int number;
		char password[20];
		for(unsigned int i=0;i<number_command;++i)
		{
			scanf("%s %u %s",command,&number,password);
			if(command[0]=='N')
			{
				unordered_map<unsigned int,string>::iterator iter=user_info.find(number);
				if(iter!=user_info.end())
				   printf("ERROR: Exist\n");
				else
				{
					user_info.insert(make_pair(number,password));
					printf("New: OK\n");
				}
			}
			else if(command[0]=='L')
			{
				unordered_map<unsigned int,string>::iterator iter=user_info.find(number);
				if(iter!=user_info.end())
				{
					if(iter->second==password)
						printf("Login: OK\n");
					else
						printf("ERROR: Wrong PW\n");
				}
				else
					printf("ERROR: Not Exist\n");
			}
		}
	}
	return 0;
}*/

#include  <stdio.h>
#include  <string.h>
#include  <string>
#include  <vector>
using namespace std;

struct user
{
	unsigned int number;
	string password;
	user(unsigned int n,string s):number(n),password(s){}
};

vector<user> user_info[10000];

int main()
{
	unsigned int number_command;
	while(scanf("%u",&number_command)!=EOF)
	{
		char command[2];
		unsigned int number;
		char password[20];
		for(unsigned int i=0;i<number_command;++i)
		{
			scanf("%s %u %s",command,&number,password);
			vector<user>& user_array=user_info[number>>20];
			vector<user>::iterator iter=user_array.begin();
			for(;iter!=user_array.end();++iter)
				if(iter->number==number)
					break;
			if(command[0]=='N')
			{
				
				if(iter!=user_array.end())
				   printf("ERROR: Exist\n");
				else
				{
					user_array.push_back(user(number,password));
					printf("New: OK\n");
				}
			}
			else if(command[0]=='L')
			{
				if(iter!=user_array.end())
				{
					if(iter->password==password)
						printf("Login: OK\n");
					else
						printf("ERROR: Wrong PW\n");
				}
				else
					printf("ERROR: Not Exist\n");
			}
		}
	}
	return 0;
}