#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <string>
#include  <map>
using namespace std;

map<string,bool> records;
int win_moves[20];
int win_count;


bool win_func(vector<int> arry,bool first)
{
	bool result=false;
	int process[20];
	int index=0;
	for(int i=2;i<=20;++i)
	{
		if(arry[i]==1)
			process[index++]=i;
	}
	
	if(index==0)
		return false;
	string refer;
	for(int i=0;i<index;++i)
	{
		char str[3];
		sprintf(str,"%02d",process[i]);
		refer.append(str);
	}
	
	map<string,bool>::iterator iter=records.find(refer);
	if(iter!=records.end())
		return iter->second;

	for(int i=0;i<index;++i)
	{
		vector<int> temp_arry(arry);
		int temp=process[i];
		while(temp<=20)
		{
			temp_arry[temp]=0;
			for(int j=2;j<20;++j)
			{
				if(temp_arry[j]==1)
					continue;
				if(j+temp<=20)
					temp_arry[j+temp]=0;
				else
					break;
			}
			temp+=process[i];		
		}
		bool flag=win_func(temp_arry,false);
		if(!flag)
		{
			result=true;
			if(first)
				win_moves[win_count++]=process[i];
		}
	}
	records[refer]=result;
	return result;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			int num;
			win_count=0;
			scanf("%d",&num);
			vector<int> arry(21);
			win_count=0;
			for(int j=0;j<num;++j)
			{
				int temp;
				scanf("%d",&temp);
				arry[temp]=1;
			}
			printf("Scenario #%d:\n",i+1);
			win_func(arry,true);
			if(win_count==0)
				printf("There is no winning move.\n\n");
			else
			{
				printf("The winning moves are:");
				for(int j=0;j<win_count;++j)
				   printf(" %d",win_moves[j]);
				printf(".\n\n");
			}
		}
	}
	return 0;
}