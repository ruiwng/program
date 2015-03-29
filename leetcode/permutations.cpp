#include  <vector>
#include  <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		sort(num.begin(),num.end());
		vector<vector<int> > result;
        do
		{
			result.push_back(num);
		}while(next_permutation(num.begin(),num.end()));
		return result;
    }
};

int main()
{

}