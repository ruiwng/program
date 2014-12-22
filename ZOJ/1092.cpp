/*
#include  <stdio.h>
#include  <string.h>
#include  <map>
#include  <vector>
#include  <string>
using namespace std;

double currency[31][31];

map<string,int> index_info;

struct info
{
	int currency_number;
	double value;
	info(int c=0,double v=0.0):currency_number(c),value(v){}
};

int n;
bool success;
int object;

void DFS(vector<int> traversed,int current_index,double value)
{
	for(int i=0;i<n;++i)
	{
		if(currency[current_index][i]!=0.0&&traversed[i]==0)
		{
			double temp=value*currency[current_index][i];
			if(i==object)
			{
				if(temp>1.0)
				{
					success=true;
					return;
				}
			}
			else
			{
				vector<int> traversed_temp(traversed);
			    traversed_temp[i]=1;
				DFS(traversed_temp,i,temp);
			}
		}
	}
}

int main()
{
	int case_number=1;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int index=0;
		memset(currency,0,sizeof(currency));
		index_info.clear();
		for(int i=0;i<n;++i)
		{
			char str[30];
			scanf("%s",str);
			index_info[str]=index++;
		}

		int m;
		scanf("%d",&m);
		for(int i=0;i<m;++i)
		{
			char str1[30],str2[30];
			double c;
			scanf("%s%lf%s",str1,&c,str2);
			currency[index_info[str1]][index_info[str2]]=c;
		}
		success=false;
		for(int i=0;i<n;++i)
		{
			object=i;
			vector<int> traversed_tags(n);
			DFS(traversed_tags,i,1.0);
			if(success)
				break;
		}
		if(success)
			printf("Case %d: Yes\n",case_number++);
		else
			printf("Case %d: No\n",case_number++);
	}
	return 0;
}
*/

#include  <stdio.h>
#include  <stdio.h>
#include  <string.h>
#include  <map>
#include  <string>
using namespace std;

double currency[31][31];

map<string,int> index_info;

int main()
{
	int case_number=1;
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int index=0;
		memset(currency,0,sizeof(currency));
		index_info.clear();
		for(int i=0;i<n;++i)
		{
			char str[30];
			scanf("%s",str);
			index_info[str]=index++;
		}

		int m;
		scanf("%d",&m);
		for(int i=0;i<m;++i)
		{
			char str1[30],str2[30];
			double c;
			scanf("%s%lf%s",str1,&c,str2);
			currency[index_info[str1]][index_info[str2]]=c;
		}
		bool success=false;
		
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
				for(int k=0;k<n;++k)
					if(j!=k&&currency[j][i]!=0.0&&currency[i][k]!=0.0)
					{
						if(currency[j][i]*currency[i][k]>currency[j][k])
							currency[j][k]=currency[j][i]*currency[i][k];
					}
			}
		}
		for(int i=0;!success&&i<n;++i)
			for(int j=0;!success&&j<n;++j)
			{
				if(currency[i][j]!=0.0&&currency[j][i]!=0.0&&currency[i][j]*currency[j][i]>1.0)
					success=true;

			}
		if(success)
			printf("Case %d: Yes\n",case_number++);
		else
			printf("Case %d: No\n",case_number++);
	}
	return 0;
}