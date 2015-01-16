#include  <string>
#include  <map>
#include  <vector>
using namespace std;

struct cmp_func
{
	bool operator()(const vector<int>& lhs,const vector<int>& rhs) const
	{
		for(int i=0;i<26;++i)
		{
			if(lhs[i]!=rhs[i])
				return lhs[i]<rhs[i];
		}
	}
};

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> result;
		map<vector<int>,int,cmp_func> agagrams_info;
		int len=strs.size();
		for(int i=0;i<len;++i)
		{
			vector<int> temp(26,0);
			int len2=strs[i].length();
			for(int j=0;j<len2;++j)
			   ++temp[strs[i][j]-'a'];
			map<vector<int>,int,cmp_func>::iterator iter=agagrams_info.find(temp);
			if(iter!=agagrams_info.end())
			{
				if(iter->second!=-1)
				{
					result.push_back(strs[iter->second]);
					iter->second=-1;
				}
				result.push_back(strs[i]);
			}
			else
			    agagrams_info.insert(make_pair(temp,i));
		}
		return result;
    }
};

int main()
{

}