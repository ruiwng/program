#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <algorithm>
using namespace std;

int arry[]={10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int main()
{
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		while(t-->0)
		{
			int temp;
			scanf("%d",&temp);
			int num_length=1;
			int index=0;
			int len=0;
			vector<int> length_arry;
			length_arry.push_back(0);
			for(int i=1;;++i)
			{
				if(i==arry[index])
				{
					++num_length;
					++index;
				}
				len+=num_length;
				length_arry.push_back(len);
				if(temp<=len)
					break;
				else
					temp-=len;
			}
			vector<int>::iterator iter=lower_bound(length_arry.begin(),length_arry.end(),temp);
			int pos=iter-length_arry.begin();
			temp-=length_arry[pos-1];
			char str[30];
			sprintf(str,"%d\n",pos);
			printf("%c\n",str[temp-1]);
		}
	}
	return 0;
}