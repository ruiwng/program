#include  <string>
using namespace std;

const char* record[3]=
	{
		"IVX",
		"XLC",
		"CDM",	
	};
int n[3]={1,10,100};
class Solution {
public:
    string intToRoman(int num) {
        string result;
		if(num>=1000)
		{
			int k=num/1000;
			num%=1000;
			result.assign(k,'M');
		}
		int k;
		if(num>=100)
			k=2;
		else if(num>=10)
			k=1;
		else
			k=0;
		while(k>=0)
		{
			int temp=num/n[k];
			num%=n[k];
			if(temp>=5&&temp<=8)
			{
				temp-=5;
				result.push_back(record[k][1]);
			}
			if(temp>=0&&temp<=3)
				result.append(temp,record[k][0]);
			else
			{
				result.push_back(record[k][0]);
				if(temp==4)
					result.push_back(record[k][1]);
				else
					result.push_back(record[k][2]);
			}
			--k;
		}
		return result;
    }
};

int main()
{
	Solution s;
	string result=s.intToRoman(3999);
	return 0;
}