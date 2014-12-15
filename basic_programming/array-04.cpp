#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

int main()
{
     unsigned int num;
	 int object;
	 while(scanf("%u %d",&num,&object)!=EOF)
	 {
		 vector<int> num_array(num);
		 for(unsigned int i=0;i<num;++i)
			 scanf("%d",&num_array[i]);

		 vector<int>::iterator iter=find(num_array.begin(),num_array.end(),object);
		 if(iter==num_array.end())
			 printf("Not Found\n");
		 else
			 printf("%u\n",iter-num_array.begin());
	 }
	 return 0;
}