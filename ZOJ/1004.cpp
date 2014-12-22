#include  <stdio.h>
#include  <string.h>
#include  <stack>
#include  <algorithm>
using namespace std;

bool is_legal(char* source,char* dest)
{
	int len1=strlen(source);
	int len2=strlen(dest);
	if(len1!=len2)
		return false;
	int hash[260];
	memset(hash,0,sizeof(hash));
	for(int i=0;i<len1;++i)
		++hash[source[i]];
	for(int j=0;j<len2;++j)
		--hash[dest[j]];
	for(int i=0;i<260;++i)
		if(hash[i]!=0)
			return false;
	return true;
}

int main()
{
	char source[1000],dest[1000];	
	while(scanf("%s",source)!=EOF)
	{
		scanf("%s",dest);
		printf("[\n");
		if(is_legal(source,dest))
		{
			char opera[2000];
			int len=strlen(source);
			int c=0;
			for(int i=0;i<len;++i)
				opera[c++]='i';
			for(int i=0;i<len;++i)
				opera[c++]='o';
			do
			{
				char *p=source;
				char *q=dest;
				int i=0;
				stack<char> char_stack;
				for(;i<c;++i)
				{
					if(opera[i]=='i')
						char_stack.push(*p++);
					else 
					{
						if(char_stack.empty()||char_stack.top()!=*q)
							break;
						else
						{
							char_stack.pop();
							++q;
						}
					}
				}
				if(i==c)
				{
					for(int j=0;j<c;++j)
						printf("%c ",opera[j]);
					printf("\n");
				}
			}while(next_permutation(opera,opera+c));
		}
		printf("]\n");
	}
	return 0;
}