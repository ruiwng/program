#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <string>
using namespace std;

struct char_sets
{
	vector<int> pos_array;
	string characters;
};
int main()
{
	int k[3];
	while(scanf("%d%d%d",&k[0],&k[1],&k[2])!=EOF)
	{
		if(k[0]==0&&k[1]==0&&k[2]==0)
			break;

		char str[100];
		scanf("%s",str);
		char* p=str;
		int pos=0;
		char_sets sets[3];
		while(*p!='\0')
		{
			if(*p>='a'&&*p<='i')
			{
				sets[0].pos_array.push_back(pos);
				sets[0].characters.push_back(*p);
			}
			else if(*p>='j'&&*p<='r')
			{
				sets[1].pos_array.push_back(pos);
				sets[1].characters.push_back(*p);
			}
			else
			{
				sets[2].pos_array.push_back(pos);
				sets[2].characters.push_back(*p);
			}
			++pos;
			++p;
		}
		for(int i=0;i<3;++i)
		{
			if(sets[i].characters.length()==0)
				continue;
			k[i]=k[i]%sets[i].characters.length();
			string& chars_temp=sets[i].characters;
			vector<int>& pos_temp=sets[i].pos_array;
			rotate(chars_temp.begin(),chars_temp.end()-k[i],chars_temp.end());
			int length=pos_temp.size();
			for(int j=0;j<length;++j)
				str[pos_temp[j]]=chars_temp[j];
		}
		printf("%s\n",str);
	}
	return 0;
}