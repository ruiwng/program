#include  <string>
#include  <vector>
#include  <unordered_map>
using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s){
    int len=s.length();
    vector<string> result;
    if(len<10)
      return result;
    unordered_map<int,int> repeat_record;
    int pos=0;
    for(int i=0;i<9;++i)
      pos=(pos<<2)+get_pos(s[i]);
    for(int i=9;i<len;++i)
    {
	pos=(pos<<2)+get_pos(s[i]);
	if(++repeat_record[pos]==2)
	  result.push_back(s.substr(i-9,10));
	pos&=0x3ffff;
    }
    return result;
  }
private:
  inline int get_pos(char c)
  {
    if(c=='A')
      return 0;
    else if(c=='T')
      return 1;
    else if(c=='G')
      return 2;
    else
      return 3;
  }
};

int main()
{
  Solution s;
  vector<string> result=s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
  return 0;
}
