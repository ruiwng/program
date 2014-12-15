#include  <stdio.h>
#include  <list>
#include  <functional>

using namespace std;
int main()
{
	unsigned int number_coupons,number_products;
	while(scanf("%u",&number_coupons)!=EOF)
	{
		list<int> coupons_array;
		list<int> products_array;
		for(unsigned int i=0;i<number_coupons;++i)
		{
			int coupon_temp;
			scanf("%d",&coupon_temp);
			coupons_array.push_back(coupon_temp);
		}
		coupons_array.sort(greater<int>());
		scanf("%u",&number_products);
		for(unsigned int i=0;i<number_products;++i)
		{
			int product_temp;
			scanf("%d",&product_temp);
			products_array.push_back(product_temp);
		}
		products_array.sort(greater<int>());

		int amount=0;
		while(!coupons_array.empty()&&!products_array.empty())
		{
			int coupon_temp=coupons_array.front();
			int product_temp=products_array.front();
			coupons_array.pop_front();
			products_array.pop_front();
			if(coupon_temp<=0||product_temp<=0)
				break;
			amount+=coupon_temp*product_temp;
		}

		while(!coupons_array.empty()&&!products_array.empty())
		{
			int coupon_temp=coupons_array.back();
			int product_temp=products_array.back();
			coupons_array.pop_back();
			products_array.pop_back();
			if(coupon_temp>=0||product_temp>=0)
				break;
			amount+=coupon_temp*product_temp;
		}
		printf("%d\n",amount);
	}
	return 0;
}