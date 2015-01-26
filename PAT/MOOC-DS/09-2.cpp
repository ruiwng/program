#include  <stdio.h>
#include  <string>
#include  <unordered_map>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		unordered_map<int,string> user_info;
		for(int i=0;i<n;++i)
		{
			char instruction[2];
			int number;
			char password[20];
			scanf("%s%d%s",instruction,&number,password);
			unordered_map<int,string>::iterator iter=user_info.find(number);
			if(instruction[0]=='N')
			{
				if(iter==user_info.end())
				{
					user_info.insert(make_pair(number,password));
					printf("New: OK\n");
				}
				else
					printf("ERROR: Exist\n");
			}
			else
			{
				if(iter==user_info.end())
				   printf("ERROR: Not Exist\n");
				else if(iter->second!=password)
					printf("ERROR: Wrong PW\n");
				else
					printf("Login: OK\n");
			}
		}
	}
	return 0;
}