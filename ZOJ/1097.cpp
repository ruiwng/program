#include  <stdio.h>
#include  <string.h>
#include  <set>
#include  <algorithm>
using namespace std;

set<int> trees[51];

int high_bound;
int generate_tree(char* str)
{
	char* p=str;
	++p;
	int number=0;
	while(*p>='0'&&*p<='9')
		number=number*10+*p++-'0';
	if(high_bound<number)
		high_bound=number;
	while(*p!=')')
	{
		char temp[1000];
		memset(temp,0,sizeof(temp));
		int t=0;
		char* q=temp;
		while(1)
		{
			if(*p=='(')
				++t;
			else if(*p==')')
			{
				if(--t==0)
				{
				    *q=')';
					break;
				}
			}
			*q++=*p++;
		}
		int child=generate_tree(temp);
	    trees[number].insert(child);
		trees[child].insert(number);
		++p;
	}
	return number;
}

int main()
{
	char str[1000];
	while(fgets(str,1000,stdin)!=NULL)
	{
		if(str[0]=='\n')
			break;
		str[strlen(str)-1]='\0';
		high_bound=0;
		char *p=remove(str,str+strlen(str),' ');
		*p='\0';
		generate_tree(str);
		bool flag=true;
		while(true)
		{
			int i=1;
			for(;i<=high_bound;++i)
			{
				if(trees[i].size()==1)
				{	
					if(flag)
						flag=false;
					else
						printf(" ");
					printf("%d",*trees[i].begin());
					trees[*trees[i].begin()].erase(i);
					trees[i].clear();
					break;
				}
			}
			if(i>high_bound)
				break;
		}
		printf("\n");
	}
	return 0;
}
