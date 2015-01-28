#include  <string>
#include  <unordered_map>
#include  <stdlib.h>
#include  <string.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
		unordered_map<long long,int> pos_record;//record all the division
        string result;
		long long n=numerator,d=denominator;
		if((n<0&&d>0)||(n>0&&d<0))
			result.push_back('-');
		n=abs(n);
		d=abs(d);
		char str[30];
		sprintf(str,"%lld",n/d);
		result.append(str);
		n%=d;
		if(n==0)
			return result;
		result.push_back('.');
		n*=10;
		while(true)
		{
			unordered_map<long long,int>::iterator iter=pos_record.find(n);//find whether n has already do the division, if so, a recursion exist.
			if(iter!=pos_record.end())
			{
				result.insert(result.begin()+iter->second,'(');
				result.push_back(')');
				break;
			}
			
			result.push_back(n/d+'0');
			pos_record.insert(make_pair(n,result.size()-1));
			n%=d;
			if(n==0)//if the remainder is zero, exit the loop.
				break;
			n*=10;
		}
		return result;
    }
};

int main()
{
	Solution s;
	string result=s.fractionToDecimal(1,99);
	return 0;
}