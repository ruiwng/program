#include  <vector>
#include  <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
		int len = citations.size();

		int result = 0;
		for(int i = len - 1; i >= 0; --i)
		{
			int temp = len - i;
			if((i != 0 && citations[i] >= temp && citations[i - 1] <= temp) ||
				(i == 0 && citations[i] >= temp))
			{
				result = temp;
				break;
			}
		}
		return result;
    }
};

int main()
{
	Solution s;
	int citations[] = {3, 0, 6, 1, 5};
	int result = s.hIndex(vector<int>(citations, citations + 5));
	return 0;
}