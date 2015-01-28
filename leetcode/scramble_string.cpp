#include  <string.h>
#include  <string>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
		if(s1==s2)
			return true;
		int len=s1.length();
		if(len==1&&s1!=s2)
			return false;
		int record[260];
		memset(record,0,sizeof(record));
		int num=0;
		for(int i=0;i<len;++i)
		{
			if(++record[static_cast<int>(s1[i])]==0)
				--num;
			else if(record[static_cast<int>(s1[i])]==1)
				++num;
			if(--record[static_cast<int>(s2[i])]==0)
			{
				if(--num==0&&i!=len-1)
				{
					if(isScramble(s1.substr(0,i+1),s2.substr(0,i+1))&&isScramble(s1.substr(i+1),s2.substr(i+1)))
						return true;
				}
			}
			else if(record[static_cast<int>(s2[i])]==-1)
				++num;
		}
		if(num!=0)
			return false;
		for(int i=0;i<len;++i)
		{
			if(++record[static_cast<int>(s1[i])]==0)
				--num;
			else if(record[static_cast<int>(s1[i])]==1)
				++num;
			if(--record[static_cast<int>(s2[len-1-i])]==0)
			{
				if(--num==0&&i!=len-1)
				{
					if(isScramble(s1.substr(0,i+1),s2.substr(len-i-1))&&isScramble(s1.substr(i+1),s2.substr(0,len-i-1)))
						return true;
				}
			}
			else if(record[static_cast<int>(s2[len-1-i])]==-1)
				++num;
		}
		return false;
    }
};

int main()
{
	string s1("eqxuljcvzyatwvicnaaqthxaxpibrh");	           
	string s2("eaaaahribpxxhtqncivwtyzvcjluxq");
	Solution s;
	bool result=s.isScramble(s1,s2);
	return 0;
}