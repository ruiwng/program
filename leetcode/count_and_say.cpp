#include  <string.h>
#include  <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result("1");
		int count=1;
		while(count<n)
		{
			string temp;
			int i=0;
			while(i<result.size())
			{
				int k=i+1;
				while(k<result.size()&&result[k]==result[i])
					++k;
				char str[20];
				sprintf(str,"%d",k-i);
				temp.append(str);
				temp.push_back(result[i]);
				i=k;
			}
			result.swap(temp);
			++count;
		}
		return result;
    }
};

int main()
{
	
}