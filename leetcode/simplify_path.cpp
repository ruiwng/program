#include  <string>
#include  <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int len=path.size();
		vector<string> path_array;
		path_array.push_back("/");
		int i=1;
		string current_path;
		while(i<len)
		{
			if(path[i]!='/')
				current_path+=path[i];
			else if(current_path!="")
			{
				if(current_path=="..")
				{
					if(path_array.size()>1)
				         path_array.pop_back();
				}
			    else if(current_path!=".")
			    {
				  if(path_array.size()>1)
					path_array.push_back("/"+current_path);
				  else
					path_array.push_back(current_path);
			    }
				current_path="";
			}
			++i;
		}
		if(current_path!="")
		{
			if(current_path=="..")
			{
				if(path_array.size()>1)
				        path_array.pop_back();
			}
			else if(current_path!=".")
			{
				if(path_array.size()>1)
					path_array.push_back("/"+current_path);
				else
					path_array.push_back(current_path);
			}
		}
		string result;
		int path_len=path_array.size();
		for(int i=0;i<path_len;++i)
			result+=path_array[i];
		return result;
    }
};

int main()
{
	Solution s;
	string result=s.simplifyPath("///");
	return 0;
}