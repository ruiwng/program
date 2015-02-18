#include  <stdio.h>
#include  <map>
#include  <string>
using namespace std;

int main()
{
	map<string,int> num_map;
	int num=1;
	string t("a");
	while(true)
	{
		num_map.insert(make_pair(t,num++));
		if(num>83681)
			break;
		int len=t.length();
		int i=len-1;
		for(;i>=0;--i)
		{
			if(t[i]+1<='z'-(len-1-i))
				break;
		}
		if(i<0)
		{
			t.insert(t.begin(),1,'a');
			i=0;
		}
		else
			++t[i];
		for(int j=i+1;j<t.length();++j)
			t[j]=t[i]+j-i;
	}
	char str[10];
	while(scanf("%s",&str)!=EOF)
	{
		map<string,int>::iterator iter=num_map.find(str);
		if(iter==num_map.end())
			printf("0\n");
		else
			printf("%d\n",iter->second);
	}
	return 0;
}