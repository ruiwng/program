#include  <stdio.h>
#include  <vector>
#include  <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> result;
        int len=words.size();
		int start=0;
		while(start<len)
		{
			int end=start;
			int current_len=0;
			while(end<len)
			{
				current_len+=words[end].length();
				if(end!=start)
					++current_len;
				if(current_len>L)
				{
					current_len-=words[end].length()+1;
					break;
				}
				else
					++end;
			}
			string temp(words[start]);
			if(end-start==1)
				temp.append(L-words[start].length(),' ');
			else if(end!=len)
			{
				int backspace_length=L-current_len;
				int space_len=backspace_length/(end-start-1);
				int num=backspace_length%(end-start-1);
				for(int i=start+1;i<end;++i)
				{
					if(i-start<=num)
						temp.append(space_len+2,' ');
					else
						temp.append(space_len+1,' ');
					temp.append(words[i]);
				}				
			}
			else
			{
				for(int i=start+1;i<end;++i)
				{
					temp.push_back(' ');
					temp.append(words[i]);
				}
				temp.append(L-temp.length(),' ');
			}
			result.push_back(temp);
			start=end;
		}
		return result;
    }
};

int main()
{
	const char *str[]={"What","must","be","shall","be."};
	Solution s;
	vector<string> words;
	words.assign(str,str+5);
	vector<string> result=s.fullJustify(words,12);
	for(int i=0;i<result.size();++i)
		printf("%s\n",result[i].c_str());
	return 0;
}