/*
#include  <stdio.h>
#include  <vector>
#include  <queue>
#include  <algorithm>
#include  <string.h>
using namespace std;

typedef struct 
{
	unsigned int index;
	unsigned int process_time;
}customer;

inline void print_time(unsigned int time)
{
	printf("%02u:%02u\n",time/60+8,time%60);
}

int main()
{
	unsigned int number_window,max_capacity,number_customer,
		number_query;
	while(scanf("%u %u %u %u",&number_window,&max_capacity,
		&number_customer,&number_query)!=EOF)
	{
		queue<customer> custom_queue;
		for(unsigned int i=0;i<number_customer;++i)
		{
			customer customer_temp;
		    scanf("%u",&customer_temp.process_time);
			customer_temp.index=i+1;
			custom_queue.push(customer_temp);
		}

		getchar();
		char query_array[4000];
		fgets(query_array,4000,stdin);
		unsigned int query_length=strlen(query_array);

		if(query_array[query_length-1]=='\n')
			query_array[query_length-1]='\0';

		vector<queue<customer> > window_queue(number_window);

		unsigned int index=0;
		while(!custom_queue.empty()&&window_queue[number_window-1].size()!=max_capacity)
		{
			window_queue[(index++)%number_window].push(custom_queue.front());
			custom_queue.pop();
		}

		vector<unsigned int> window_time(number_window);
		for(unsigned int i=0;i<number_window;++i)
		{
			if(window_queue[i].empty())
				window_time[i]=600;
			else
			    window_time[i]=window_queue[i].front().process_time;
		}

		vector<unsigned int> process_time(number_customer+1);
		unsigned int current_time=0;
		while(true)
		{
			vector<unsigned int>::iterator iter=min_element(window_time.begin(),window_time.end());
			unsigned int index=iter-window_time.begin();
			if(!window_queue[index].empty())
			{
				process_time[window_queue[index].front().index]=*iter;
				if(*iter>=540)
					break;
				window_queue[index].pop();

				if(!custom_queue.empty())
			    {
				   window_queue[index].push(custom_queue.front());
				   custom_queue.pop();
			    }

				if(window_queue[index].empty())
				    *iter=600;
				else
				    *iter+=window_queue[index].front().process_time;
			}
			
		}
		unsigned int query_temp;

		char* temp=query_array;
		while(sscanf(temp,"%u",&query_temp)==1)
		{
			if(process_time[query_temp]!=0)
				print_time(process_time[query_temp]);
			else
				printf("Sorry\n");
			temp=strchr(temp,' ');
			if(temp==NULL)
				break;
			else
				temp+=1;
		}
	}
	return 0;
}*/

#include  <stdio.h>
#include  <vector>
#include  <queue>
using namespace std;

struct customer
{
	unsigned int number;
	unsigned int process_time;
};

struct window
{
	unsigned int current_time;
	bool close;
	window():current_time(0),close(false){}
};

void print_time(unsigned int temp)
{
      printf("%02u:%02u\n",8+temp/60,temp%60);
}

int main()
{
	unsigned int number_window,max_capacity,number_customer,
		number_query;
	while(scanf("%u %u %u %u",&number_window,&max_capacity,&number_customer,
		&number_query)!=EOF)
	{
		unsigned int temp=number_window*max_capacity;
		vector<queue<customer> > queue_array(number_window);
		queue<customer> last_queue;
		for(unsigned int i=1;i<=number_customer;++i)
		{
			customer customer_temp;
			scanf("%u",&customer_temp.process_time);
			customer_temp.number=i;
			if(i<=temp)
			   queue_array[(i-1)%number_window].push(customer_temp);
			else
				last_queue.push(customer_temp);
		}

		vector<unsigned int> query_array(number_query);
		for(unsigned int i=0;i<number_query;++i)
		   scanf("%u",&query_array[i]);

		vector<unsigned int> finish_time(number_customer+1,-1);

		vector<window> window_array(number_window);
		for(unsigned int i=0;i<number_window;++i)
		{
			if(!queue_array[i].empty())
			   window_array[i].current_time=queue_array[i].front().process_time;
			else
				window_array[i].close=true;
		}

		while(true)
		{
			unsigned int current_window=number_window;
			for(unsigned int i=0;i<number_window;++i)
			{
				if(window_array[i].close)
					continue;
				if(current_window==number_window||window_array[i].current_time<window_array[current_window].current_time)
					current_window=i;
			}

			if(current_window==number_window)
				break;

			customer& customer_temp=queue_array[current_window].front();
			finish_time[customer_temp.number]=window_array[current_window].current_time;
			if(window_array[current_window].current_time>=540)
				window_array[current_window].close=true;
			queue_array[current_window].pop();
			if(!last_queue.empty())
			{
				queue_array[current_window].push(last_queue.front());
				last_queue.pop();
			}
			if(queue_array[current_window].empty())
				window_array[current_window].close=true;
			else
			    window_array[current_window].current_time+=queue_array[current_window].front().process_time;
		}

		for(unsigned int i=0;i<number_query;++i)
		{
			if(finish_time[query_array[i]]==-1)
				printf("Sorry\n");
			else
				print_time(finish_time[query_array[i]]);
		}
	}
	return 0;
}