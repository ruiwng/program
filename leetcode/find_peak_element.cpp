#include  <stdio.h>
#include  <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int length=num.size();
		int i=0;
		while(true)
		{
			if((i>0&&num[i]<=num[i-1])||(i<length-1&&num[i]<=num[i+1]))
				++i;
			else
				return i;
		}
    }
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(1);
	Solution s;
	int result=s.findPeakElement(num);
	return 0;
}