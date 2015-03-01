#include  <stdio.h>
#include  <string.h>
#include  <set>
#include  <string>
using namespace std;

char excuses_array[20][80];
int main()
{
	int num_keywords,num_excuses;
	int execuse_set=0;
	while(scanf("%d%d",&num_keywords,&num_excuses)!=EOF)
	{
		set<string> keywords_set;
		for(int i=0;i<num_keywords;++i)
		{
			char str[25];
			scanf("%s",str);
			keywords_set.insert(str);
		}
		getchar();
		for(int i=0;i<num_excuses;++i)
			fgets(excuses_array[i],80,stdin);

		int max_keyword=0;
		int max_index[20];
		int excuse_num=0;
		printf("Excuse Set #%d\n",++execuse_set);
		for(int i=0;i<num_excuses;++i)
		{
			char str[80];
			int keyword_num=0;
			strcpy(str,excuses_array[i]);
			char *p=str;
			while(true)
			{
				if(*p>='A'&&*p<='Z')
					*p=*p-'A'+'a';
				else if(*p=='\n')
				{
					*p=' ';
					break;
				}
				else if(!isalpha(*p))
					*p=' ';
				++p;
			}
			p=str;
			while(*p==' ')
				++p;
			char temp[80];
			while(sscanf(p,"%s",temp)==1)
			{
				if(keywords_set.find(temp)!=keywords_set.end())
					++keyword_num;
				p=strchr(p,' ');
				if(p==NULL)
					break;
				while(*p==' ')
					++p;
			}
			if(keyword_num>max_keyword)
			{
				max_keyword=keyword_num;
				excuse_num=0;
				max_index[excuse_num++]=i;
			}
			else if(keyword_num==max_keyword)
				max_index[excuse_num++]=i;
		}
		for(int i=0;i<excuse_num;++i)
			printf("%s",excuses_array[max_index[i]]);
		printf("\n");
	}
	return 0;
}