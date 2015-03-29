#include  <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int length=digits.size();
        int carry=0;
        if(length==0)
           digits.push_back(1);
        else
        {
          for(int i=length-1;i>=0;--i)
          {
            int temp;
            if(i==length-1)
               temp=digits[i]+carry+1;
            else
               temp=digits[i]+carry;
            if(temp>=10)
            {
                temp-=10;
                carry=1;
            }
            else
                carry=0;
            digits[i]=temp;
        }
        if(carry==1)
           digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
int main()
{
	vector<int> num;
	num.push_back(1);
	Solution s;
	vector<int> result=s.plusOne(num);
	return 0;
}