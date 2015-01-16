#include  <vector>
#include  <string.h>
#include  <string>
#include  <algorithm>
using namespace std;

struct cmp
{
	bool operator()(const string& lhs,const string& rhs) const
	{
		return lhs+rhs>rhs+lhs;
	}
};

class Solution {
public:
    string largestNumber(vector<int> &num) {
		vector<string> str_array;
		int len=num.size();
	    for(int i=0;i<len;++i)
	    {
			char str[100];
			sprintf(str,"%d",num[i]);
			str_array.push_back(str);
		}
		sort(str_array.begin(),str_array.end(),cmp());
		string result;
		for(int i=0;i<len;++i)
			result+=str_array[i];
		while(result.size()>1&&result[0]=='0')
			result.erase(result.begin());
		return result;
    }
};
int main()
{
	int arry[]={3,30,34,5,9};
	Solution s;
	string result=s.largestNumber(vector<int>(arry,arry+5));
	return 0;
}