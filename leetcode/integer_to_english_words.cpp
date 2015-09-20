#include  <string>
using namespace std;

const char *str1[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", 
"Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const char *str2[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
class Solution {
public:
    string numberToWords(int num) {
		string result;
		bool first = true;
        int x = num / 1000000000;
		if( x != 0)
		{
			first = false;
			result += realize(x) + string(" Billion");
			num -= x * 1000000000;
		}
		int y = num / 1000000;
		if(y != 0)
		{
			if(first)
				first = false;
			else
				result += " ";
			result += realize(y) + string(" Million");
			num -= y * 1000000;
		}
		int z = num / 1000;
		if(z != 0)
		{
			if(first)
				first = false;
			else
				result += " ";
			result += realize(z) + string(" Thousand");
			num -= z * 1000;
		}
		if(num != 0)
		{
			if(first)
				first = false;
			else
				result += " ";
			result += realize(num);
		}
		if(result.empty())
			result = "Zero";
		return result;
    }
private:
	string realize(int num)
	{
		string result;
		bool first = true;
		int x = num / 100;
		if( x != 0)
		{
		    first = false;
			result += str1[x] + string(" Hundred");
			num -= x * 100;
		}

		if(num < 20)
		{
			if(num != 0)
			{
				if(first)
					first = false;
				else
					result += " ";
				result += str1[num];
			}
		}
		else 
		{
			if(first)
				first = false;
			else
				result += " ";
			int a = num / 10;
			int b = num % 10;
			result += str2[a - 2];
			if(b != 0)
				result += " " + string(str1[b]);
		}
		return result;
	}
	
};

int main()
{
	Solution s;
	string result = s.numberToWords(123);
	result = s.numberToWords(12345);
	result = s.numberToWords(1234567);
	return 0;
}