#include  <stdio.h>
#include  <list>
using namespace std;

struct item
{
	int coefficient;
	int exponent;
	item(int coe=0,int exp=0):coefficient(coe),exponent(exp){}
};


void print_polynomial(const list<item>& lst_array)
{
	if(lst_array.empty())
		printf("0 0\n");
	else
	{
		printf("%d %d",lst_array.begin()->coefficient,lst_array.begin()->exponent);
		for(list<item>::const_iterator iter=++lst_array.begin();iter!=lst_array.end();++iter)
			printf(" %d %d",iter->coefficient,iter->exponent);
		printf("\n");
	}
}

int main()
{
	list<item> lst[2];
	for(unsigned int i=0;i<2;++i)
	{
	  unsigned int num;
	  scanf("%u",&num);
	  for(unsigned j=0;j<num;++j)
	  {
		 item item_temp;
		 scanf("%d %d",&item_temp.coefficient,&item_temp.exponent);
		 lst[i].push_back(item_temp);
	  }
	}

	list<item> product_lst;
	list<item>::const_iterator iter1,iter2;
	for(iter1=lst[0].begin();iter1!=lst[0].end();++iter1)
		for(iter2=lst[1].begin();iter2!=lst[1].end();++iter2)
		{
			item item_temp(iter1->coefficient*iter2->coefficient,iter1->exponent+iter2->exponent);
			list<item>::iterator iter=product_lst.begin();
			while(iter!=product_lst.end()&&iter->exponent>item_temp.exponent)
				iter++;
			if(iter!=product_lst.end()&&iter->exponent==item_temp.exponent)
			{
				iter->coefficient+=item_temp.coefficient;
				if(iter->coefficient==0)
					product_lst.erase(iter);
			}
			else
				product_lst.insert(iter,item_temp);
		}


	list<item> sum_lst;
	iter1=lst[0].begin();
	iter2=lst[1].begin();
	while(iter1!=lst[0].end()&&iter2!=lst[1].end())
	{
		if(iter1->exponent>iter2->exponent)
		{
			sum_lst.push_back(*iter1);
			iter1++;
		}
		else if(iter1->exponent==iter2->exponent)
		{
			item item_temp(iter1->coefficient+iter2->coefficient,iter1->exponent);
			if(item_temp.coefficient!=0)
			  sum_lst.push_back(item_temp);
			iter1++;
			iter2++;
		}
		else
		{
			sum_lst.push_back(*iter2);
			iter2++;
		}
	}
	while(iter1!=lst[0].end())
	{
	  sum_lst.push_back(*iter1);
	  ++iter1;
	}
	while(iter2!=lst[1].end())
	{
	  sum_lst.push_back(*iter2);
	  ++iter2;
	}

	print_polynomial(product_lst);
	print_polynomial(sum_lst);
	return 0;
}