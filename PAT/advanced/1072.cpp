#include  <stdio.h>
#include  <vector>
#include  <string>
#include  <string.h>
using namespace std;

int dist[1011][1011];

struct node
{
	unsigned int node_distance;
	bool known;
	node():node_distance(1000000),known(false){}
};
int main()
{
	unsigned int total_house,total_station,number_road,max_range;
	while(scanf("%u %u %u %u",&total_house,&total_station,&number_road,&max_range)!=EOF)
	{
		getchar();
		for(unsigned int i=0;i<number_road;++i)
		{
			char str[100];
			fgets(str,100,stdin);
			unsigned int len=strlen(str);
			if(str[len-1]=='\n')
				str[len-1]='\0';
			bool tag1=false,tag2=false;
			unsigned int position_temp1,position_temp2,distance_temp;
			
			string str_temp(str);
			size_t index=str_temp.find_first_not_of(' ');
			if(str_temp[index]=='G')
				tag1=true;
			index=str_temp.find_first_of(' ',index);
			index=str_temp.find_first_not_of(' ',index);
			if(str_temp[index]=='G')
				tag2=true;
			if(!tag1&&!tag2)
			    sscanf(str,"%u %u %u",&position_temp1,&position_temp2,&distance_temp);
			else if(tag1&&tag2)
				sscanf(str,"G%u G%u %u",&position_temp1,&position_temp2,&distance_temp);
			else if(tag1&&!tag2)
			    sscanf(str,"G%u %u %u",&position_temp1,&position_temp2,&distance_temp);
			else if(!tag1&&tag2)
				sscanf(str,"%u G%u %u",&position_temp1,&position_temp2,&distance_temp);
			if(tag1)
				position_temp1+=total_house;
			if(tag2)
				position_temp2+=total_house;
			dist[position_temp1][position_temp2]=dist[position_temp2][position_temp1]=distance_temp;
		}

		unsigned int total_position=total_house+total_station+1;
		
		int optimal=-1;
		unsigned int sum_distance=0;
		unsigned int min_distance=0;
		for(unsigned int i=1;i<=total_station;++i)
		{
			vector<node> node_array(total_position);
			node_array[total_house+i].node_distance=0;
			unsigned int sum_temp=0;
			unsigned int temp_min=0;
			vector<unsigned int> satisfy_node;
			while(true)
			{
			    unsigned int current_distance=1000001;
			    unsigned int current_node;								
			    for(unsigned int j=1;j<total_position;++j)
			    {
					if(node_array[j].known)
						continue;
				    if(node_array[j].node_distance<current_distance)
				    {
					  current_node=j;
					  current_distance=node_array[j].node_distance;
				    }
			    }
			    if(current_distance==1000001)
					break;
				node_array[current_node].known=true;
				
				if(current_node<=total_house)
				{
					if(node_array[current_node].node_distance>max_range)
						break;
					sum_temp+=node_array[current_node].node_distance;
					satisfy_node.push_back(current_node);
					if(temp_min==0||node_array[current_node].node_distance<temp_min)
						temp_min=node_array[current_node].node_distance;
					if(satisfy_node.size()==total_house)
					{
						if(optimal==-1||temp_min>min_distance)
						{
							optimal=i;
							sum_distance=sum_temp;
							min_distance=temp_min;
						}
						else if(temp_min==min_distance&&sum_distance>sum_temp)
						{
							sum_distance=sum_temp;
							optimal=i;
						}
						break;
					}
				}

				for(unsigned int j=1;j<total_position;++j)
				{
					if(node_array[j].known||dist[current_node][j]==0)
						continue;
					if(node_array[current_node].node_distance+dist[current_node][j]<node_array[j].node_distance)
						node_array[j].node_distance=node_array[current_node].node_distance+dist[current_node][j];
				}
			}
		}
		if(optimal==-1)
			printf("No Solution\n");
		else
		{
			printf("G%d\n",optimal);
			printf("%.1lf %.1lf\n",static_cast<double>(min_distance),static_cast<double>(sum_distance)/total_house);
		}
	}
	return 0;
}