#include  <stdio.h>
#include  <deque>
#include  <functional>
#include  <algorithm>

using namespace std;

int main()
{
	unsigned int number_ticket,number_good;
	while(scanf("%u",&number_ticket)!=EOF)
	{
		deque<int> ticket_array(number_ticket);
		for(unsigned int i=0;i<number_ticket;++i)
			scanf("%d",&ticket_array[i]);


		scanf("%u",&number_good);
		deque<int> good_array(number_good);
		for(unsigned int i=0;i<number_good;++i)
	        scanf("%d",&good_array[i]);

		sort(ticket_array.begin(),ticket_array.end(),greater<int>());
		sort(good_array.begin(),good_array.end(),greater<int>());
		int sum=0;
		while(!ticket_array.empty()&&!good_array.empty()&&ticket_array.front()>0&&good_array.front()>0)
		{
			sum+=ticket_array.front()*good_array.front();
			ticket_array.pop_front();
			good_array.pop_front();
		}
		while(!ticket_array.empty()&&!good_array.empty()&&ticket_array.back()<0&&good_array.back()<0)
		{
			sum+=ticket_array.back()*good_array.back();
			ticket_array.pop_back();
			good_array.pop_back();
		}
		printf("%d\n",sum);
	}
}