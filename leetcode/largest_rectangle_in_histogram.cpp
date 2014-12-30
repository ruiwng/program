#include  <vector>
#include  <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
		if(height.empty())
			return 0;
		int len=height.size();
		bool sorted=false;
		if(is_sorted(height.begin(),height.end()))
			sorted=true;
		int max_area=0;
		int i=0;
		if(sorted)
		{
			while(i<len)
			{
				int area_temp=height[i]*(len-i);
				if(area_temp>max_area)
					max_area=area_temp;
				++i;
			}
		}
		else
		{
			while(i<len)
			{
				int min_height=height[i];
				int current_min=i;
				int min_index=i;
				for(int j=i;j<len;++j)
				{
					if(height[j]<min_height)
					{
						min_index=j;
						min_height=height[j];
					}
					int area_temp=min_height*(j-i+1);
					if(max_area<area_temp)
					{
						max_area=area_temp;
						current_min=min_index;
					}
				}
				i=current_min+1;		
			}
		}		
		return max_area;
    }
};

int main()
{
	Solution s;
	int arry[]={2,1,5,6,2,3};
	vector<int> test(arry,arry+sizeof(arry)/sizeof(int));
	int result=s.largestRectangleArea(test);
	return 0;
}