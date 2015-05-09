#include  <stdio.h>
#include  <string>
#include  <unordered_map>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		unordered_map<int,string> record;
		for(int i=0;i<n;++i)
		{
			char operation[2];
			int qq_number;
			char password[20];
			scanf("%s%d%s",operation,&qq_number,password);
			unordered_map<int,string>::iterator iter=record.find(qq_number);
			if(operation[0]=='L')
			{
				if(iter==record.end())
					printf("ERROR: Not Exist\n");
				else if(iter->second==password)
					printf("Login: OK\n");
				else
					printf("ERROR: Wrong PW\n");
			}
			else 
			{
				if(iter!=record.end())
					printf("ERROR: Exist\n");
				else
				{
					record.insert(make_pair(qq_number,password));
					printf("New: OK\n");
				}
			}
		}
	}
}