#include  <stdio.h>
#include  <map>
#include  <vector>
using namespace std;

int arr[256][256];
int win_arr[2][256];

int main()
{
	unsigned int num;
	while(scanf("%u\n",&num)!=EOF)
	{
		arr['C']['C']=0;
	    arr['C']['J']=1;
	    arr['C']['B']=-1;

	    arr['J']['C']=-1;
	    arr['J']['J']=0;
	    arr['J']['B']=1;

	    arr['B']['C']=1;
	    arr['B']['J']=-1;
	    arr['B']['B']=0;

		vector<int> info(3);
		for(unsigned int i=0;i<num;++i)
		{
			char temp1,temp2;
			char str[5];
			fgets(str,5,stdin);
			sscanf(str,"%c %c",&temp1,&temp2);
			
			int result=arr[temp1][temp2];
			switch(result)
			{
			case 1:
				info[0]++;
				win_arr[0][temp1]++;
				break;
			case 0:
				info[1]++;
				break;
			case -1:
				info[2]++;
				win_arr[1][temp2]++;
				break;
			}
		}
		printf("%d %d %d\n",info[0],info[1],info[2]);
		printf("%d %d %d\n",info[2],info[1],info[0]);
		for(unsigned int i=0;i<2;++i)
		{
			if(win_arr[i]['B']>=win_arr[i]['C']&&win_arr[i]['B']>=win_arr[i]['J'])
				printf("B");
			else if(win_arr[i]['C']>win_arr[i]['B']&&win_arr[i]['C']>=win_arr[i]['J'])
				printf("C");
			else
				printf("J");
			if(i==0)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}