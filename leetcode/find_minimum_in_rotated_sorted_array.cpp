#include  <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int len=num.size();
		int start=0;
		int end=len-1;
		if(num[start]<=num[end])
			return num[start];
		int median;
		while(start<=end)
		{
			median=(start+end)>>1;
			if(num[median]<num[median-1])
				return num[median];
			else if(num[median]>num[median+1])
				return num[median+1];
			if(num[median]>=num[start])
				start=median+1;
			else if(num[median]<=num[end])
				end=median-1;
		}
    }
};

int main()
{
	Solution s;
	vector<int> num;
	num.push_back(2);
	num.push_back(1);

	int result=s.findMin(num);
	return 0;
}