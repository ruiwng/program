#include  <vector>
#include  <queue>
#include  <string>
#include  <unordered_set>
#include  <unordered_map>
using namespace std;

struct record
{
	string current_str;
	int transform;
	record(const string& s=string(),int t=0):current_str(s),transform(t){}
};


class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        dict.erase(start);
		dict.erase(end);
		queue<record> record_queue;
		record_queue.push(record(start,0));
		bool flag=false;//find the minimum transformation
		int min_transform;//the minimum transformation
		int current_transform=0;
		vector<string> current_record;
		while(!record_queue.empty())
		{
			record r=record_queue.front();
			record_queue.pop();
			//if find the minimum transformation and the current transformation is greater than the minimum, exit the loop
			if(flag&&r.transform>=min_transform)
				break;
			if(r.transform>current_transform)//if the current transformation increase, erase all record in the current_record from dict
			{
				current_transform=r.transform;
				int k=current_record.size();
				for(int i=0;i<k;++i)
					dict.erase(current_record[i]);
				current_record.clear();
			}
			int len=r.current_str.length();
			
			for(int i=0;i<len;++i)
			{
				string t=r.current_str;
				for(int j='a';j<='z';++j)//find all occurrence of transformed words in the dictionary
				{
					t[i]=j;
					if(t==end)
					{
						flag=true;
						transform_record[t].push_back(r.current_str);
						min_transform=current_transform+1;
					}
					if(dict.find(t)!=dict.end())
					{
						current_record.push_back(t);
						unordered_map<string,vector<string> >::iterator iter=transform_record.find(t);
						if(iter==transform_record.end())//the first time traverse this word, so it need to be pushed into the queue.
							record_queue.push(record(t,current_transform+1));
						transform_record[t].push_back(r.current_str);						
					}
				}
			}
		}
		vector<vector<string> > result;
		deque<string> temp;
		DFS(end,result,temp);
		return result;
    }
private://traverse all the transformation of the words 
	void DFS(const string& curr,vector<vector<string> >& result,deque<string>& path)
	{
		path.push_front(curr);
		unordered_map<string,vector<string> >::iterator iter=transform_record.find(curr);
		if(iter!=transform_record.end())
		{
			const vector<string>& transform_ref=iter->second;
			int len=transform_ref.size();
			for(int i=0;i<len;++i)
			{
				deque<string> temp=path;
				DFS(transform_ref[i],result,temp);
			}
		}
		else
			result.push_back(vector<string>(path.begin(),path.end()));
	}
private:
	unordered_map<string,vector<string> > transform_record;
};

int main()
{
	string start("a");
	string end("c");
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	Solution s;
	vector<vector<string> > result=s.findLadders(start,end,dict);
	return 0;
}