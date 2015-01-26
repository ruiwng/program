//Author: ruiwng , Email: ruiwng@zju.edu.cn
//insert all the elements into a link list and sort it, every time traverse from the beginning to find whether the corresponding element
//satisfy the condition, if it is, erase it from the link list and terminate the current traversion, otherwise go on traversing until the end of
// the link list.
#include  <stdio.h>
#include  <vector>
#include  <list>
using namespace std;

int main()
{
	int hash_size;
	while(scanf("%d",&hash_size)!=EOF)
	{
		vector<int> num_array;//record the real position of all the elements
		vector<int> tag_array(hash_size,-1);// tag the position occupied
		num_array.reserve(hash_size);
		list<int> num_list;
		for(int i=0;i<hash_size;++i)
		{
			int num;
			scanf("%d",&num);
			num_array.push_back(num);
			if(num>=0)
				num_list.push_back(num);
		}
		num_list.sort();
		bool first=true;
		while(true)
		{
			list<int>::iterator iter=num_list.begin();
			while(iter!=num_list.end())
			{
				int pos=*iter%hash_size;
				while(tag_array[pos]!=-1)
				{
					if(++pos==hash_size)
						pos=0;
				}
				if(num_array[pos]==*iter)//find the right position of the current element and erase it from the link list
				{
					tag_array[pos]=*iter;
					if(first)
						first=false;
					else
						printf(" ");
					printf("%d",*iter);
					num_list.erase(iter);
					break;
				}
				++iter;//if the current element doesn't find the right position, go on traversing
			}
			if(num_list.empty())//if the link list is empty, terminate the loop.
				break;
		}
		printf("\n");
	}
	return 0;
}