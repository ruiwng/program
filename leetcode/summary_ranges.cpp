#include  <string.h>
#include  <vector>
#include  <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		int start, end;
		char temp[100];
		int len = nums.size();
		for(int i = 0; i < len; ++i)
		{
			if(i == 0)
			{
				start = nums[i];
				end = start;
			}
			else
			{
				if(nums[i] == end + 1)
					++end;
				else
				{
					if(end == start)
						sprintf(temp, "%d", start);
					else
						sprintf(temp, "%d->%d", start, end);
					result.push_back(temp);
					start = nums[i];
					end = start;
				}
			}
		}
		if(len != 0)
		{
			if(end == start)
			   sprintf(temp, "%d", start);
		    else
			   sprintf(temp, "%d->%d", start, end);
		    result.push_back(temp);
		}
		return result;
    }
};


int main()
{
	Solution s;
	int arry[] = {0, 1, 2, 4, 5, 7};
	vector<string> result = s.summaryRanges(vector<int>(arry, arry + 6));
	return 0;
}
