#include  <string>
#include  <queue>
#include  <unordered_set>
using namespace std;

struct record
{
	string current_str;
	int transform;
	record(const string& s=string(),int t=0):current_str(s),transform(t){}
};

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dict.erase(start);
		queue<record> record_queue;
		record_queue.push(record(start,0));
		while(!record_queue.empty())
		{
			record r=record_queue.front();
			record_queue.pop();
			int len=r.current_str.length();
			for(int i=0;i<len;++i)
			{
				string t=r.current_str;
				for(int j='a';j<='z';++j)
				{
					t[i]=j;
					if(t==end)
						return r.transform+2;
					if(dict.find(t)!=dict.end())
					{
						dict.erase(t);
						record_queue.push(record(t,r.transform+1));
					}
				}
			}
		}
		return 0;
    }
};

int main()
{
	string start("hit");
	string end("cog");
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	Solution s;
	int result=s.ladderLength(start,end,dict);
	return 0;
}