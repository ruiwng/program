#include  <stdio.h>
#include  <vector>
using namespace std;

struct node
{
	bool known;
	vector<unsigned int> connects;
	node():known(false),connects(){}
};

void DFT(vector<node>& cities,unsigned int num,unsigned int concern_index)
{
	cities[num].known=true;
	unsigned int size_temp=cities[num].connects.size();
	for(unsigned int i=0;i<size_temp;++i)
	{
		unsigned int temp=cities[num].connects[i];
		if(temp==concern_index)
			continue;
		if(!cities[temp].known)
		   DFT(cities,temp,concern_index);
	}
}

int main()
{
	unsigned int number_city,number_highway,concern;
	while(scanf("%u %u %u",&number_city,&number_highway,&concern)!=EOF)
	{
		vector<node> city_array(number_city+1);
		for(unsigned int i=0;i<number_highway;++i)
		{
			unsigned int city1,city2;
			scanf("%u %u",&city1,&city2);
			city_array[city1].connects.push_back(city2);
			city_array[city2].connects.push_back(city1);
		}
		vector<unsigned int> concern_array(concern);

		for(unsigned int i=0;i<concern;++i)
		   scanf("%u",&concern_array[i]);

		for(unsigned int i=0;i<concern;++i)
		{
			unsigned int connects=0;
			for(unsigned int j=1;j<number_city+1;++j)
				city_array[j].known=false;
			for(unsigned int j=1;j<number_city+1;++j)
			{
				if(j==concern_array[i])
					continue;
				if(city_array[j].known==false)
				{
					connects++;
					DFT(city_array,j,concern_array[i]);
				}
			}
			printf("%u\n",connects-1);
		}
	}
	return 0;
}