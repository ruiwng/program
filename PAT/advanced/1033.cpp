#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

struct station
{
	double price;
	double distance;
	bool operator<(const station& s) const
	{
		return this->distance<s.distance;
	}
};

int main()
{
	double max_capacity,distance,unit_distance;
	unsigned int number_station;
	while(scanf("%lf %lf %lf %u",&max_capacity,&distance,
		&unit_distance,&number_station)!=EOF)
	{
		vector<station> station_array(number_station);
		for(unsigned int i=0;i<number_station;++i)
			scanf("%lf %lf",&station_array[i].price,&station_array[i].distance);

		sort(station_array.begin(),station_array.end());


		double current_capacity=0.0;
		double long_distance=max_capacity*unit_distance;
		double sum_price=0.0;
		double current_distance=0.0;
		for(vector<station>::iterator iter=station_array.begin();iter!=station_array.end();
			++iter)
		{

			double temp_distance=min(iter->distance,distance);
			current_capacity-=(temp_distance-current_distance)/unit_distance;
			current_distance=temp_distance;
			if(current_capacity<0)
				break;			
			if(current_distance==distance)
				break;
			vector<station>::iterator iter2;
			for(iter2=next(iter);iter2!=station_array.end();++iter2)
			{
				if(iter2->distance>iter->distance+long_distance)
					break;
				if(iter2->price<=iter->price)
					break;
			}
			if(iter2!=station_array.end()&&iter2->price<iter->price)
			{			
				double oil_temp;
				if(iter2->distance<distance)
				    oil_temp=(iter2->distance-iter->distance)/unit_distance;
				else
					oil_temp=(distance-iter->distance)/unit_distance;
				if(oil_temp>max_capacity)
					oil_temp=max_capacity;
				if(oil_temp>current_capacity)
				{
					sum_price+=(oil_temp-current_capacity)*iter->price;
					current_capacity=oil_temp;
				}
			}
			else
			{
				double oil_temp=(distance-iter->distance)/unit_distance;
				if(oil_temp>max_capacity)
					oil_temp=max_capacity;
				if(oil_temp>current_capacity)
				{
					sum_price+=(oil_temp-current_capacity)*iter->price;
					current_capacity=oil_temp;
				}
			}	
		}
		current_distance+=current_capacity*unit_distance;
		if(current_distance<distance)
			printf("The maximum travel distance = %.2lf\n",current_distance);
		else
			printf("%.2lf\n",sum_price);
	}
	return 0;
}