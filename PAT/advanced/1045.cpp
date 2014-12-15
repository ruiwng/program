/*
#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <map>
using namespace std;

vector<unsigned int> favorite_array;
vector<unsigned int> strip_array;
unsigned int number_favorite;

struct key
{
	unsigned int position_temp;
	unsigned int number_temp;
	key(unsigned int position,unsigned int number):position_temp(position),number_temp(number){}
	bool operator<(const key& k) const
	{
		if(this->position_temp!=k.position_temp)
			return this->position_temp<k.position_temp;
		return this->number_temp<k.number_temp;
	}
};

map<key,unsigned int> info_array;
unsigned int max_strip(unsigned int start,unsigned int min_threshold)
{
	if(start==strip_array.size())
		return 0;
	if(strip_array[start]==favorite_array[min_threshold])
		return max_strip(start+1,min_threshold)+1;
	else
	{
		unsigned int max_number=0;
	    unsigned int temp_max;
    	unsigned int temp=strip_array.size();
	    for(unsigned int i=min_threshold;i<number_favorite;++i)
	    {
		   vector<unsigned int>::iterator iter=find(strip_array.begin()+start,strip_array.end(),favorite_array[i]);
		   if(iter==strip_array.end())
			   continue;

		   if(i!=min_threshold&&iter-strip_array.begin()>temp)
			  continue;
		   temp=iter-strip_array.begin();
		   map<key,unsigned int>::iterator iter_info=info_array.find(key(temp+1,i));
		   if(iter_info!=info_array.end())
			   temp_max=iter_info->second;
		   else
		   {
		       temp_max=max_strip(temp+1,i);
			   info_array.insert(make_pair(key(temp+1,i),temp_max));
		   }
		   if(temp_max+1>max_number)
			  max_number=temp_max+1;
	    }
	    return max_number;
	}
}

int main()
{
	unsigned int total_color;
	while(scanf("%u",&total_color)!=EOF)
	{
		scanf("%u",&number_favorite);
		favorite_array.resize(number_favorite);
		for(unsigned int i=0;i<number_favorite;++i)
			scanf("%u",&favorite_array[i]);

		unsigned int strip_length;
		scanf("%u",&strip_length);
		strip_array.resize(strip_length);
		for(unsigned int i=0;i<strip_length;++i)
			scanf("%u",&strip_array[i]);
		
		unsigned int max_length=max_strip(0,0);
		printf("%u\n",max_length);
	}
	return 0;
}
*/

#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

vector<unsigned int> favorite_array;
vector<unsigned int> strip_array;
unsigned int number_favorite;

unsigned int info_array[2100000];
unsigned int max_strip(unsigned int start,unsigned int min_threshold)
{
	unsigned int temp_max;
	if(start==strip_array.size())
		return 0;
	if(strip_array[start]==favorite_array[min_threshold])
	{
		temp_max=info_array[(start+1)*202+min_threshold];
		if(temp_max==0)
		{
		     temp_max=max_strip(start+1,min_threshold);
			 info_array[(start+1)*202+min_threshold]=temp_max;
		}
		return temp_max+1;
	}
	else
	{
		unsigned int max_number=0;    
    	unsigned int temp=strip_array.size();
	    for(unsigned int i=min_threshold;i<number_favorite;++i)
	    {
		   vector<unsigned int>::iterator iter=find(strip_array.begin()+start,strip_array.end(),favorite_array[i]);
		   if(iter==strip_array.end())
			   continue;

		   if(i!=min_threshold&&iter-strip_array.begin()>temp)
			  continue;
		   temp=iter-strip_array.begin();
		   temp_max=info_array[(temp+1)*202+i];
		   if(temp_max==0)
		   {
		       temp_max=max_strip(temp+1,i);
			   info_array[(temp+1)*202+i]=temp_max;
		   }
		   if(temp_max+1>max_number)
			  max_number=temp_max+1;
	    }
	    return max_number;
	}
}

int main()
{
	unsigned int total_color;
	while(scanf("%u",&total_color)!=EOF)
	{
		scanf("%u",&number_favorite);
		favorite_array.resize(number_favorite);
		for(unsigned int i=0;i<number_favorite;++i)
			scanf("%u",&favorite_array[i]);

		unsigned int strip_length;
		scanf("%u",&strip_length);
		strip_array.resize(strip_length);
		for(unsigned int i=0;i<strip_length;++i)
			scanf("%u",&strip_array[i]);
		
		unsigned int max_length=max_strip(0,0);
		printf("%u\n",max_length);
	}
	return 0;
}