#include  <string.h>
#include  <string>
#include  <deque>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        memset(tag1,0,sizeof(tag1));
		memset(tag2,0,sizeof(tag2));
        int len=T.size();
        for(int i=0;i<len;++i)
            ++tag2[static_cast<int>(T[i])];
        deque<int> index_deque;
        bool success=false;
        int len2=S.size();
        int num=0;
        int start;
        int min_length=0x7fffffff;
        for(int i=0;i<len2;++i)
        {
            if(tag2[static_cast<int>(S[i])]>0)
            {
                index_deque.push_back(i);
                if(++tag1[static_cast<int>(S[i])]<=tag2[static_cast<int>(S[i])])
                {
                    if(++num==len)
                        success=true;
                }
                while(tag1[static_cast<int>(S[index_deque.front()])]>tag2[static_cast<int>(S[index_deque.front()])])
                {
                    --tag1[static_cast<int>(S[index_deque.front()])];
                    index_deque.pop_front();
                    
                }                   
                if(success)
                {
                    if(i-index_deque.front()<min_length)
                    {
                        min_length=i-index_deque.front();
                        start=index_deque.front();
                    }
                        
                }
            } 
        }
        if(!success)
            return "";
        else
            return S.substr(start,min_length+1);
    }
private:
    int tag1[260];
	int tag2[260];
};

int main()
{
	Solution s;
	string result=s.minWindow("ADOBECODEBANC","ABC");
	return 0;
}