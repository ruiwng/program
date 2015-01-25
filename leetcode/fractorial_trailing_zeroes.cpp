class Solution {
public:
    int trailingZeroes(int n) {
        int result=0;
		while(n>0)
		{
			n/=5;
			result+=n;
		}
		return result;
    }
};

int main()
{
	Solution s;
	int result=s.trailingZeroes(25);
	return 0;
}