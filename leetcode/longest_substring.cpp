#include  <string>
#include  <string.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int record[260];
		memset(record,0,sizeof(record));
		int max_length=0;
		int current_length=0;
		int len=s.length();
		int start=0;
		int i=0;
		while(i<len)
		{
			while(i<len&&++record[static_cast<int>(s[i])]==1)
			{
				++current_length;
				++i;
			}
			if(current_length>max_length)
				max_length=current_length;
			if(i==len)
				break;
			else
			{
				while(s[start]!=s[i])
				{
					--record[static_cast<int>(s[start++])];
					--current_length;
				}
				--record[static_cast<int>(s[start++])];
			}
			++i;
		}
		return max_length;
    }
};

int main()
{
	Solution s;
	int length=s.lengthOfLongestSubstring("hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac");
	return 0;
}