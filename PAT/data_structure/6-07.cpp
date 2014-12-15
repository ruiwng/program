#include  <stdio.h>

#define   MAX_VALUE      1000000000
unsigned int distance_array[101][101];
int main()
{
	unsigned int animal_sum,record_num;
	while(scanf("%u %u",&animal_sum,&record_num)!=EOF)
	{
		for(unsigned int i=1;i<=animal_sum;++i)
			for(unsigned int j=1;j<=animal_sum;++j)
			  distance_array[i][j]=MAX_VALUE;

		for(unsigned int i=0;i<record_num;++i)
		{
			unsigned int node_temp1,node_temp2;
			unsigned int distance;
			scanf("%u %u %u",&node_temp1,&node_temp2,&distance);
			distance_array[node_temp1][node_temp2]=distance_array[node_temp2][node_temp1]=distance;
		}
		for(unsigned int i=1;i<=animal_sum;++i)
		{
			for(unsigned int j=1;j<=animal_sum;++j)
			{
				for(unsigned int k=1;k<=animal_sum;++k)
				{
					if(distance_array[j][i]+distance_array[i][k]<distance_array[j][k])
						distance_array[j][k]=distance_array[j][i]+distance_array[i][k];
				}
			}
		}
		unsigned int index;
		unsigned int long_distance=MAX_VALUE;
		bool exist=true;
		for(unsigned int i=1;i<=animal_sum;++i)
		{
			unsigned int current_longest=0;
			for(unsigned int j=1;j<=animal_sum;++j)
			{
				if(i==j)
					continue;
				if(distance_array[i][j]>current_longest)
					current_longest=distance_array[i][j];
			}
			if(current_longest==MAX_VALUE)
			{
				exist=false;
				break;
			}
			if(current_longest<long_distance)
			{
				long_distance=current_longest;
				index=i;
			}
		}
		if(exist)
			printf("%u %u\n",index,long_distance);
		else
			printf("0\n");
	}
	return 0;
}