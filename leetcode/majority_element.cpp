#include  <vector>
#include  <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int len=num.size();
		pos=len>>1;
		partition(num,0,len-1);
		return num[pos];
    }
private:
	void insertion_sort(vector<int>& num,int start,int end)
	{
		int k=start+1;
		while(k<=end)
		{
			int t=num[k];
			int j=k-1;
			for(;j>=start&&num[j]>t;--j)
				num[j+1]=num[j];
			num[j+1]=t;
			++k;
		}
	}
	void partition(vector<int>& num,int low,int high)
	{
		if(low+3<=high)
		{
			insertion_sort(num,low,high);
			return;
		}
		int first=low;
		int last=high;
		int key=num[first];
		while(first<last)
		{
			while(first<last&&num[last]>=key)
				--last;
			num[first]=num[last];
			while(first<last&&num[last]<=key)
				++first;
			num[last]=num[first];
		}
		num[first]=key;
		if(first<pos)
			partition(num,first+1,high);
		else if(first>pos)
			partition(num,low,first-1);
	}
private:
	int pos;
};

int main()
{
	vector<int> num(10000,1);
	Solution s;
	int result=s.majorityElement(num);
	return 0;
}