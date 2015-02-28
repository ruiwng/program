#include  <algorithm>

class Solution {
public:
    void rotate(int nums[], int n, int k) {
		std::rotate(nums,nums+n-k%n,nums+n);
    }
};

int main()
{
	int arry[]={1,2,3,4,5,6};
	Solution s;
	s.rotate(arry,6,2);
	return 0;
}