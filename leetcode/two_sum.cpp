#include  <vector>
#include  <algorithm>
using namespace std;

struct record
{
	int number;
	int index;
	record(int n=0,int i=0):number(n),index(i){}
	bool operator<(const record& r) const
	{
		return this->number<r.number;
	}
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<record> record_array;
		int len=numbers.size();
		record_array.reserve(len);
		for(int i=0;i<len;++i)
			record_array.push_back(record(numbers[i],i));
		sort(record_array.begin(),record_array.end());
		for(int i=0;i<len-1;++i)
		{
			int object=target-record_array[i].number;
			int start=i+1;
			int end=len-1;
			if(object<record_array[start].number||object>record_array[end].number)
				continue;
			int median;
			while(start<=end)
			{
				median=(start+end)>>1;
				if(record_array[median].number>object)
					end=median-1;
				else if(record_array[median].number<object)
					start=median+1;
				else
					break;
			}
			if(start<=end)
			{
				vector<int> result;
				if(record_array[i].index<record_array[median].index)
				{
					result.push_back(record_array[i].index+1);
					result.push_back(record_array[median].index+1);
				}
				else
				{
					result.push_back(record_array[median].index+1);
					result.push_back(record_array[i].index+1);
				}
				return result;
			}
		}
		return vector<int>();
    }
};

int main()
{
	Solution s;
	int arry[]={0,4,3,0};
	vector<int> result=s.twoSum(vector<int>(arry,arry+4),9);
	return 0;
}