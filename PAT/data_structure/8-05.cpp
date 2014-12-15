#include  <stdio.h>
#include  <vector>
#include  <queue>
#include  <algorithm>
using namespace std;

struct customer
{
	unsigned int arrive_time;//arrive time
	unsigned int last_time;//service time
	customer():arrive_time(0),last_time(0){}
};

struct window
{
	unsigned int number_customer;//the number of customers of current window.
	unsigned int current_time;//current time
	queue<customer> window_queue;
	window():number_customer(0),current_time(0),window_queue(){}
	bool operator<(const window& w) const
	{
		return this->number_customer<w.number_customer;
	}
};
int main()
{
	unsigned int number_customer,number_window,window_customer;
	while(scanf("%u %u %u",&number_customer,&number_window,&window_customer)!=EOF)
	{
		vector<window> window_array(number_window);
		queue<customer> customer_queue;
		customer customer_temp;
		for(unsigned int i=0;i<number_customer;++i)
		{
			scanf("%u %u",&customer_temp.arrive_time,&customer_temp.last_time);
			customer_queue.push(customer_temp);
		}
		unsigned long long sum_time=0;
		//traverse all the customers in the queue.
		while(!customer_queue.empty())
		{
			customer& customer_temp=customer_queue.front();
			//traverse very window.
			for(unsigned int i=0;i<number_window;++i)
			{
				//if the time of the head of the queue of current window is smaller than the arrive time of current customer
				//then pop it. this is a loop. and calculate the waiting time. Note that the maximum time is 60 minutes.
				while(!window_array[i].window_queue.empty())
				{
					customer& customer_window=window_array[i].window_queue.front();
					if(window_array[i].current_time+min(60u,customer_window.last_time)<=customer_temp.arrive_time)
					{
						sum_time+=window_array[i].current_time-customer_window.arrive_time;
						window_array[i].current_time+=min(60u,customer_window.last_time);
						window_array[i].window_queue.pop();
						--window_array[i].number_customer;
					}
					else
						break;
				}
			}
			//select the window for which the customers waiting is minimum.
			vector<window>::iterator iter=min_element(window_array.begin(),window_array.end());
			//if the minimum window queue is full. select the window whose queue pop earliest.
			if(iter->number_customer>=window_customer)
			{
				vector<window>::iterator iter_min=window_array.begin();
				unsigned int min_time=iter_min->current_time+min(60u,iter_min->window_queue.front().last_time);
				for(vector<window>::iterator iter_temp=next(window_array.begin());iter_temp!=window_array.end();++iter_temp)
				{
					unsigned int time_temp=iter_temp->current_time+min(60u,iter_temp->window_queue.front().last_time);
					if(time_temp<min_time)
					{
						min_time=time_temp;
						iter_min=iter_temp;
					}
				}
				customer& first_customer=iter_min->window_queue.front();
				sum_time+=iter_min->current_time-first_customer.arrive_time;
				iter_min->current_time+=min(60u,first_customer.last_time);
				iter_min->window_queue.pop();
				--iter_min->number_customer;
				iter=iter_min;
			}
			//the queue which iter point to is the final selection.
			if(iter->number_customer==0&&iter->current_time<customer_temp.arrive_time)
				iter->current_time=customer_temp.arrive_time;
			//enter the window queue.
			iter->window_queue.push(customer_temp);
			++iter->number_customer;
			customer_queue.pop();
		}
		//at the moment, all the customers are in the window queue.
		//traverse all the window queue.
		for(unsigned int i=0;i<number_window;++i)
		{
			queue<customer>& current_window_queue=window_array[i].window_queue;
			while(window_array[i].number_customer!=0)
			{
				sum_time+=window_array[i].current_time-current_window_queue.front().arrive_time;
				window_array[i].current_time+=min(60u,current_window_queue.front().last_time);
				current_window_queue.pop();
				--window_array[i].number_customer;
			}
		}
		printf("%.1lf\n",static_cast<double>(sum_time)/number_customer);
	}
	return 0;
}