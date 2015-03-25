#include  <string>
#include  <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		result.clear();
		num=n;
        temp.assign(n<<1,' ');
		generate_string(0,0,0);
		return result;
    }
private:
	void generate_string(int pos,int left,int right)
	{
		if(pos==num<<1)
		{
			result.push_back(temp);
			return;
		}
		if(left<num)
		{
			temp[pos]='(';
			generate_string(pos+1,left+1,right);
		}
		if(right<left)
		{
			temp[pos]=')';
			generate_string(pos+1,left,right+1);
		}
	}
private:
	int num;
	string temp;
	vector<string> result;
};

int main()
{
	Solution s;
	vector<string> result=s.generateParenthesis(3);
	return 0;
}