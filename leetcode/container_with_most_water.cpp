#include  <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int len=height.size();
		int i=0;
		int max_water=0;
		while(i<len-1)
		{
			if(height[i]*(len-1-i)<=max_water)
			{
				++i;
				continue;
			}
			int j=len-1;
			int current_max=0;
			int current_index=i;
			while(j>i)
			{
				if(height[j]>=height[i])
				{
					current_index=j;
					break;
				}
				else if(height[j]>current_max)
				{
					current_max=height[j];
					current_index=j;
				}
				--j;
			}
			while(current_index<len)
			{
				int temp=(current_index-i)*min(height[current_index],height[i]);
				if(temp>max_water)
					max_water=temp;
				++current_index;
			}
			if(j==i)
				break;
			else
			{
				int k=i+1;
				while(k<len-1&&height[k]<=height[i])
					++k;
				if(k==len-1)
					break;
				i=k;
			}
		}
		return max_water;
    }
};

int main()
{
	Solution s;
	int arry[]={0,2};
	int result=s.maxArea(vector<int>(arry,arry+2));
	return 0;
}