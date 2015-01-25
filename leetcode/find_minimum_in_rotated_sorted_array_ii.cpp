#include  <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        len=num.size();
		if(num[0]<num[len-1])
			return num[0];
		else
		    return min_func(num,0,len-1);
    }
private:
	int min_func(vector<int>& num,int start,int end)
	{
		if(start==end)
			return num[start];
		else if(start+1==end)
			return min(num[start],num[end]);
		int median=(start+end)>>1;
		if(median>0&&num[median]<num[median-1])
			return num[median];
		else if(median<len-1&&num[median]>num[median+1])
			return num[median+1];

		if(num[median]>num[start]||(num[median]==num[start]&&num[start]!=num[end]))
			return min_func(num,median+1,end);
		else if(num[median]<num[end]||(num[median]==num[end]&&num[start]!=num[end]))
			return min_func(num,start,median-1);
		else
			return min(min_func(num,start,median-1),min_func(num,median+1,end));		
	}
private:
	int len;
};

int main()
{
	int arry[]={3,3,3,3,3,3,3,3,1,3};
	Solution s;
	int result=s.findMin(vector<int>(arry,arry+10));
	return 0;
}