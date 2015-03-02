#include  <stdio.h>
#include  <string.h>
#include  <ctype.h>
#include  <map>
#include  <string>
#include  <vector>
#include  <algorithm>
using namespace std;

struct word
{
	string sequence;
	int frequency;
	word(const string& s,int f):sequence(s),frequency(f){}
	bool operator<(const word& w) const
	{
		if(this->frequency!=w.frequency)
			return this->frequency>w.frequency;
		return this->sequence<w.sequence;
	}
};

int main()
{
	char str[2000];
	map<string,int> sequence[5];
	//freopen("text.txt","r",stdin);
	while(fgets(str,2000,stdin)!=NULL)
	{
		char *p=str;
		while(*p!='\0')
		{
			if(!isalpha(*p))
				*p=' ';
			else if(*p>='a'&&*p<='z')
				*p=*p-'a'+'A';
			++p;
		}
		p=str;
		while(*p==' ')
			++p;
		char temp[100];
		while(sscanf(p,"%s",temp)==1)
		{
			p=strchr(p,' ');
			if(p==NULL)
				break;
			while(*p==' ')
				++p;
			int len=strlen(temp);
			for(int i=1;i<=5;++i)
			{
				for(int j=0;j<=len-i;++j)
				{
					char t[6];
					memset(t,0,sizeof(t));
					strncpy(t,temp+j,i);
					++sequence[i-1][t];
				}
			}
		}
	}
	for(int i=0;i<5;++i)
	{
		printf("Analysis for Letter Sequences of Length %d\n",i+1);
		printf("-----------------------------------------\n");
		vector<word> word_array;
		int len=sequence[i].size();
		word_array.reserve(len);
		for(map<string,int>::iterator iter=sequence[i].begin();iter!=sequence[i].end();++iter)
			word_array.push_back(word(iter->first,iter->second));
		sort(word_array.begin(),word_array.end());
		int frequency=0;
	    int num=0;
		for(int i=0;i<len;++i)
		{
			if(word_array[i].frequency!=frequency)
			{
				if(num!=0)
				   printf(")\n");
				if(++num==6)
					break;
				frequency=word_array[i].frequency;
				printf("Frequency = %d, Sequence(s) = (%s",word_array[i].frequency,word_array[i].sequence.c_str());
			}
			else
				printf(",%s",word_array[i].sequence.c_str());
		}
		if(num!=6)
			printf(")\n");
		printf("\n");
	}
	return 0;
}