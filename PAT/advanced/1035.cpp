#include  <stdio.h>
#include  <stdlib.h>
#include  <string>
#include  <vector>
using namespace std;
typedef struct
{
	string name;
	string password;
}USER;
int main()
{
	int n;
	vector<USER> userVec;

	while(scanf("%d",&n)!=EOF)
	{
		while(!userVec.empty())
			userVec.pop_back();
		for(int i=0;i<n;i++)
		{
			USER user;
			char temp1[12],temp2[12];
			scanf("%s %s",temp1,temp2);
			bool change=false;
			user.name=temp1;
			user.password=temp2;
			for(int i=0;i<user.password.size();i++)
			{
				if(user.password[i]=='1')
				{
					user.password[i]='@';
					change=true;
				}
				else if(user.password[i]=='0')
				{
					user.password[i]='%';
					change=true;
				}
				else if(user.password[i]=='l')
				{
					user.password[i]='L';
					change=true;
				}
				else if(user.password[i]=='O')
				{
					user.password[i]='o';
					change=true;
				}
			}
			if(change==true)
				userVec.push_back(user);
		}
		if(userVec.empty())
		{
			if(n==1)
				printf("There is 1 account and no account is modified\n");
			else 
				printf("There are %d accounts and no account is modified\n",n);
		}
		else
		{
			printf("%d\n",userVec.size());
			for(vector<USER>::const_iterator iter=userVec.begin();iter!=userVec.end();iter++)
			{
				printf("%s %s\n",iter->name.c_str(),iter->password.c_str());
			}
		}
	}
	return 0;
}