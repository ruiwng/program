#include  <unordered_set>
#include  <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> record;
		int len=nums.size();
		for(int i=0;i<len;++i)
		{
			if(record.insert(nums[i]).second==false)
				return true;
		}
		return false;
    }
};

int main()
{

}