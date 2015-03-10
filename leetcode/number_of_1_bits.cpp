class Solution {
public:
    int hammingWeight(unsigned int n) {
        int c=0;
		while(n!=0)
		{
			if(n&1)
				++c;
			n>>=1;
		}
		return c;
    }
};

int main()
{
	Solution s;
	int r=s.hammingWeight(11);
	return 0;
}