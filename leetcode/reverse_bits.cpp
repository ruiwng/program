#include  <stdio.h>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
		int pos=31;
		while(n!=0)
		{
			if(n&1)
				result^=1<<pos;
			--pos;
			n>>=1;
		}
		return result;
    }
};

int main()
{
	Solution s;
	uint32_t t=s.reverseBits(43261596);
	return 0;
}
