#include  <string>
#include  <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1,v2;
		get_version(v1,version1);
		get_version(v2,version2);
		int len1=v1.size(),len2=v2.size();
		int k=0;
		while(k<len1&&k<len2)
		{
			if(v1[k]>v2[k])
				return 1;
			else if(v1[k]<v2[k])
				return -1;
			++k;
		}
		if(k==len1&&k==len2)
			return 0;
		else if(k<len1)
		{
			while(k<len1&&v1[k]==0) ++k;
			if(k==len1)
				return 0;
			else
			    return 1;
		}
		else
		{
			while(k<len2&&v2[k]==0) ++k;
			if(k==len2)
				return 0;
			else
			    return -1;
		}
    }
private:
	void get_version(vector<int>& version_array,const string& version)
	{
		const char* p=version.c_str();
		while(true)
		{
			int temp;
			sscanf(p,"%d",&temp);
			version_array.push_back(temp);
			p=strchr(p,'.');
			if(p==NULL)
				break;
			++p;
		}
	}
};

int main()
{
	Solution s;
	int result=s.compareVersion("1.0","1");
	return 0;
}