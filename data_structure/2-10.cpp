#include  <stdio.h>
#include  <vector>
#include  <algorithm>

using namespace std;
int main()
{
	unsigned int pirates,diamonds;
	while(scanf("%u %u",&diamonds,&pirates)!=EOF)
	{
		vector<unsigned int> dia_array(2);
		dia_array[0]=0;
		dia_array[1]=1;
		unsigned int current_diamonds=diamonds-1;
		if(pirates==3)
			printf("%u\n",current_diamonds);
		else
		{
		    for(unsigned int i=4;i<=pirates;++i)
		    {
			   dia_array.push_back(current_diamonds);
			   sort(dia_array.begin(),dia_array.end());
			   unsigned int size_temp=dia_array.size();
			   current_diamonds=diamonds;
			   unsigned int temp=(size_temp+1)>>1;
			   for(unsigned int j=0;j<temp;++j)
			   {
				  dia_array[j]++;
				  current_diamonds-=dia_array[j];
			   }
			   for(unsigned int j=temp;j<size_temp;++j)
			      dia_array[j]=0;
		    }
		    printf("%u\n",current_diamonds);
		}
	}
	return 0;
}