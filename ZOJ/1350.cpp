#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int num_line;
	while(scanf("%d",&num_line)!=EOF)
	{
		for(int i=0;i<num_line;++i)
		{
			int cells;
			scanf("%d",&cells);
			vector<int> cells_array(cells+1);
			for(int j=2;j<=cells;++j)
			{
				int k=j;
				while(k<=cells)
				{
					if(cells_array[k]==0)
						cells_array[k]=1;
					else
						cells_array[k]=0;
					k+=j;
				}
			}
			int escape=0;
			for(int j=1;j<=cells;++j)
			{
				if(cells_array[j]==0)
					++escape;
			}
			printf("%d\n",escape);
		}
	}
	return 0;
}