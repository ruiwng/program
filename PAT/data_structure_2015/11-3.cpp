#include  <stdio.h>
#include  <vector>
#include  <list>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		vector<int> hash_table(n);
		list<int> key_array;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&hash_table[i]);
			if(hash_table[i]>=0)
				key_array.push_back(hash_table[i]);
		}
		key_array.sort();
		vector<int> record(n,0);
		bool first=true;
		while(!key_array.empty())
		{
			for(list<int>::iterator iter=key_array.begin();iter!=key_array.end();++iter)
			{
				int hash=(*iter)%n;
				while(record[hash]!=0)
				{
					if(++hash==n)
						hash=0;
				}
				if(hash_table[hash]==*iter)
				{
					record[hash]=1;
					if(first)
						first=false;
					else
						printf(" ");
					printf("%d",*iter);
					key_array.erase(iter);
					break;
				}
			}
		}
		printf("\n");
	}
	return 0;
}