#include  <vector>
#include  <unordered_set>
#include  <algorithm>
using namespace std;

struct record
{
	int sum;
	int pos1;
	int pos2;
	record(int s=0,int p1=0,int p2=0):sum(s),pos1(p1),pos2(p2){}
	bool operator<(const record& r) const
	{
		return this->sum<r.sum;
	}
};

struct hash_func
{
	int operator()(const vector<int>& s) const
	{
		return (s[0]<<3)+(s[1]<<2)+(s[2]<<1)+s[3];
	}
};

struct equal_func
{
	bool operator()(const vector<int>& lhs,const vector<int>& rhs) const
	{
		return lhs[0]==rhs[0]&&lhs[1]==rhs[1]&&lhs[2]==rhs[2]&&lhs[3]==rhs[3];
	}
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		unordered_set<vector<int>,hash_func,equal_func> result;//record all the results using hash table in case of duplication
        int len=num.size();
		vector<record> two_sum;
		two_sum.reserve(len*(len-1)/2);//all possible two sums
		for(int i=0;i<len-1;++i)
			for(int j=i+1;j<len;++j)
				two_sum.push_back(record(num[i]+num[j],i,j));

		sort(two_sum.begin(),two_sum.end());
        len=len*(len-1)/2;
		for(int i=0;i<len-1;++i)
		{
			if(target-two_sum[i].sum<two_sum[i+1].sum)//if the sum of the current element and its next element is greater than target, exit the loop. 
				break;
			//binary search the objective
			pair<vector<record>::iterator,vector<record>::iterator> iter_pair=equal_range(two_sum.begin(),two_sum.end(),record(target-two_sum[i].sum));
			for(vector<record>::iterator iter=iter_pair.first;iter!=iter_pair.second;++iter)
			{
				if(iter->pos1!=two_sum[i].pos1&&iter->pos2!=two_sum[i].pos1&&iter->pos1!=two_sum[i].pos2&&iter->pos2!=two_sum[i].pos2)
				{
					vector<int> temp;
					temp.push_back(num[two_sum[i].pos1]);
					temp.push_back(num[two_sum[i].pos2]);
					temp.push_back(num[iter->pos1]);
					temp.push_back(num[iter->pos2]);
					sort(temp.begin(),temp.end());
					result.insert(temp);
				}
			}
		}
		return vector<vector<int> >(result.begin(),result.end());
    }
};

int main()
{
	int arry[]={-471,-470,-470,-465,-460,-436,-413,-382,-352,-350,-348,-342,-309,-301,-299,-229,-203,-170,-154,-143,-134,-110,-94,-92,-88,-51,-47,-28,-27,-24,-1,17,59,78,138,149,161,163,168,197,202,226,248,279,290,344,369,379,390,391,426,444,461,472,476,477,484,488,497};
	Solution s;
	vector<int> temp(arry,arry+sizeof(arry)/sizeof(int));
	vector<vector<int> > result=s.fourSum(temp,4954);
	return 0;
}
