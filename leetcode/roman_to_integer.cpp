#include  <string>
using namespace std;

const char* record[3]=
	{
		"IVX",
		"XLC",
		"CDM",	
	};

int num[3]={1,10,100};

class Solution {
public:
    int romanToInt(string s) {
        int result=0;
		int len=s.length();
		int i=0;
		//count the digit of the thousand pos
		while(i<len&&s[i]=='M')
		{
			result+=1000;
			++i;
		}
		if(i==len)
			return result;
		//count the digit of the hundred,ten and one pos
		for(int j=2;j>=0;--j)
		{
			if(s[i]==record[j][1])
			{
				result+=5*num[j];
				++i;
			}
			while(i<len&&s[i]==record[j][0])
			{
				result+=num[j];
				++i;
			}
			if(i==len)
				return result;
			if(s[i]==record[j][1])
			{
				result+=3*num[j];
				++i;
			}
			if(i==len)
				return result;
			if(s[i]==record[j][2])
			{
				result+=8*num[j];
				++i;
			}
			if(i==len)
				return result;
		}
    }
};

int main()
{
	Solution s;
	int result=s.romanToInt("MMMCMXCIX");
	return 0;
}