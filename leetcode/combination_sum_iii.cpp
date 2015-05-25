#include  <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        num=k;
	    sum=n;
		recurse(0,1);
		return result;
    }
private:
	void recurse(int current_sum,int index)
	{
		if(current_element.size()==num&&current_sum==sum)
		{
			result.push_back(current_element);
			return;
		}
		if(current_element.size()>num||index==10)
			return;
		current_element.push_back(index);
		recurse(current_sum+index,index+1);
		current_element.pop_back();
		recurse(current_sum,index+1);
	}
private:
	int num;
	int sum;
	vector<int> current_element;
	vector<vector<int> > result;
};

int main()
{
	Solution s;
	vector<vector<int> > result=s.combinationSum3(3,15);
	return 0;
}