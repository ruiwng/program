#include  <string>
#include  <vector>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int len=s.size();
		int result=0;
		int i=0;
		while(i<len)
			result=result*26+s[i++]-'A'+1;
		return result;
    }
};

int main()
{
	Solution s;
	int result=s.titleToNumber("Z");
	result=s.titleToNumber("Y");
	result=s.titleToNumber("AA");
	result=s.titleToNumber("AB");
	return 0;
}