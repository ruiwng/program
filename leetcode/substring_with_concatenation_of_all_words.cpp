/*
#include  <stdlib.h>
#include  <string.h>

int *result;
int capacity;
int size;
int len;
int all_len;
char *record;
char **words_info;
int words_count;
int total_len;
char *str;
void insert_pos(int index)
{
	if(size>0&&index<=result[size-1])
		return;
	if(size>=capacity)
	{
		capacity<<=1;
		result=(int*)realloc(result,capacity*sizeof(int));
	}
	result[size++]=index;
}

void get_pos(int start,int end,int index)
{
	if(index==words_count)
	{
		insert_pos(start);
		return;
	}
	int s=end-total_len+len;
	if(s<0)
	{
		s+=-s/len*len;
		if(s<0)
			s+=len;
	}
	int e=start+total_len;
	if(e>all_len)
		e=all_len;
	for(int i=s;i<e;i+=len)
	{
		if(record[i]==0&&strncmp(&str[i],words_info[index],len)==0)
		{
			record[i]=1;
			int new_start=start<i?start:i;
			int new_end=end>i?end:i;
			get_pos(new_start,new_end,index+1);
			record[i]=0;
		}
	}
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
	    str=s;
	    words_info=words;
		words_count=wordsSize;
	    capacity=2;
		size=0;
		result=(int*)malloc(capacity*sizeof(int));
		len=strlen(words[0]);
		total_len=len*wordsSize;
		all_len=strlen(s);
		record=(char*)malloc(all_len*sizeof(char));
		memset(record,0,all_len*sizeof(char));

		char *p=strstr(s,words[0]);
		while(p!=NULL)
		{
			int index=p-s;
			record[index]=1;
			get_pos(index,index,1);
			record[index]=0;
			p=strstr(p+1,words[0]);
		}
		*returnSize=size;
		return result;
}

int main()
{
	char *words[2]={"foo","bar"};
	int resultsize;
	int *r=findSubstring("barfoothefoobarman",words,2,&resultsize);
	return 0;
}

*/
/*
#include  <stdlib.h>
#include  <string.h>

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int len=strlen(words[0]);
	int total_len=strlen(s);
	int str_len=len*wordsSize;
	int bound=total_len-str_len;
	char *records=(char*)malloc(wordsSize);
	int capacity=2;
	*returnSize=0;
	int *result=(int*)malloc(capacity*sizeof(int));
	for(int i=0;i<=bound;++i)
	{
		int k=i;
		int j=0;
		memset(records,0,wordsSize);
		int num=0;
		while(num<wordsSize)
		{
			int j=0;
			for(;j<wordsSize;++j)
		    {
			   if(records[j]==0&&strncmp(&s[k],words[j],len)==0)
			   {
				  records[j]=1;
				  ++num;
				  break;
			   }
		    }
			if(j==wordsSize)
				break;
			else
				k+=len;
		}
		if(num==wordsSize)
		{
			if(*returnSize>=capacity)
			{
				capacity<<=1;
				result=(int*)realloc(result,capacity*sizeof(int));
			}
			result[(*returnSize)++]=i;
		}
	}
	return result;
}

int main()
{
	char *words[2]={"a","b"};
	int resultsize;
	int *r=findSubstring("aaa",words,2,&resultsize);
	return 0;
}

*/
/*
#include  <vector>
#include  <string>
#include  <queue>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
        int len=words[0].length();
		int words_num=words.size();
		int total_len=s.length();
		int str_len=len*words.size();
		int bound=total_len-len;
		vector<int> record;
		for(int i=0;i<len;++i)
		{
			record.assign(words_num,0);
			queue<int> traversed_array;
			int start=i;
			int end=start;
			while(end<=bound)
			{
				string temp=s.substr(end,len);
				int k=0;
				for(;k<words_num;++k)
				{
					if(record[k]==0&&words[k]==temp)
					{
						record[k]=1;
						traversed_array.push(k);
						break;
					}
				}
				end+=len;
				if(k==words_num)
				{
					while(!traversed_array.empty()&&words[traversed_array.front()]!=temp)
					{
						record[traversed_array.front()]=0;
						traversed_array.pop();
						start+=len;
					}
					if(traversed_array.empty())
						start=end;
					else
					{
						traversed_array.push(traversed_array.front());
						traversed_array.pop();
						start+=len;
					}
				}
				else if(end-start==str_len)
				{
					result.push_back(start);
					start+=len;
					record[traversed_array.front()]=0;
					traversed_array.pop();
				}
			}
		}
		return result;
    }
};

int main()
{
	vector<string> words(100,"a");
	string object(10000,'a');
	Solution s;
	vector<int> result=s.findSubstring(object,words);
	return 0;
}
*/

#include  <stdlib.h>
#include  <string.h>

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
	    int capacity=2;
		*returnSize=0;
        int *result=(int*)malloc(capacity*sizeof(int));
        int len=strlen(words[0]);
		int words_num=wordsSize;
		int total_len=strlen(s);
		int str_len=len*words_num;
		char *bound=s+total_len-len;
		char *record=(char*)malloc(words_num*sizeof(char));
		int *q=(int*)malloc((words_num+2)*sizeof(int));
		for(int i=0;i<len;++i)
		{
			memset(record,0,words_num);
			int q_start=0,q_end=0;
			char *start=s+i;
			char *end=start;
			while(end<=bound)
			{
				int k=0;
				for(;k<words_num;++k)
				{
					if(record[k]==0&&strncmp(words[k],end,len)==0)
					{
						record[k]=1;
						q[q_end]=k;
						if(++q_end==words_num+2)
							q_end=0;
						break;
					}
				}
				end+=len;
				if(k==words_num)
				{
					while(q_start!=q_end&&strncmp(words[q[q_start]],end-len,len)!=0)
					{
						record[q[q_start]]=0;
						if(++q_start==words_num+2)
							q_start=0;
						start+=len;
					}
					if(q_start==q_end)
						start=end;
					else
					{
						q[q_end++]=q[q_start];
						if(q_end==words_num+2)
							q_end=0;
						if(++q_start==words_num+2)
							q_start=0;
						start+=len;
					}
				}
				else if(end-start==str_len)
				{
					if(*returnSize==capacity)
					{
						capacity<<=1;
						result=(int*)realloc(result,capacity*sizeof(int));
					}
					result[(*returnSize)++]=start-s;
					start+=len;
					record[q[q_start]]=0;
					if(++q_start==words_num+2)
						q_start=0;
				}
			}
		}
		return result;

}

int main()
{
	char *words[3]={"aa","aa","aa"};
	int resultsize;
	int *r=findSubstring("aaaaaaaa",words,3,&resultsize);
	return 0;
}