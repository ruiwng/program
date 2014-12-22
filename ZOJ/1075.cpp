#include  <stdio.h>
#include  <algorithm>
using namespace std;

char cards[12][5];

bool is_legal(int* s)
{
	for(int i=0;i<4;++i)
	{
		if(!((cards[s[0]][i]==cards[s[1]][i]&&cards[s[0]][i]==cards[s[2]][i])||
			(cards[s[0]][i]!=cards[s[1]][i]&&cards[s[0]][i]!=cards[s[2]][i]&&cards[s[1]][i]!=cards[s[2]][i])))
			return false;
	}
	return true;
}

int sel[12]={1,1,1,0,0,0,0,0,0,0,0,0};
int main()
{
	int num=0;
	while(scanf("%s",cards[0])!=EOF)
	{
		for(int i=1;i<12;++i)
			scanf("%s",cards[i]);
		if(++num!=1)
			printf("\n");
		printf("CARDS: ");
		for(int i=0;i<12;++i)
			printf(" %s",cards[i]);

		printf("\nSETS:   ");
		int number=0;
		do
		{
			int s[3];
			int i=0;
			for(int j=0;j<12;++j)
				if(sel[j]==1)
					s[i++]=j;
			if(is_legal(s))
			{
				if(number)
					printf("        ");
				printf("%d.  %s %s %s\n",++number,cards[s[0]],cards[s[1]],cards[s[2]]);
			}
		}while(prev_permutation(sel,sel+12));
		if(number==0)
			printf("*** None Found ***\n");
	}
	return 0;
}