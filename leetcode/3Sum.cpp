#include  <vector>
#include  <algorithm>
using namespace std;
/*
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

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		sort(num.begin(),num.end());
		int len=num.size();
		vector<record> two_sum;
		two_sum.reserve(len*(len-1)/2);
		bool flag=true;
		for(int i=0;i<len-1;++i)
		{
			if(num[i]==num[i+1])
			{
				flag=false;
				continue;
			}
			if(!flag)
				two_sum.push_back(record(num[i-1]+num[i],i-1,i));
			flag=true;
			for(int j=i+1;j<len;++j)
			{
				if(j!=i+1&&num[j]==num[j-1])
					continue;
				two_sum.push_back(record(num[i]+num[j],i,j));
			}
		}
		if(!flag)
			two_sum.push_back(record(num[len-1]+num[len-2],len-2,len-1));
		sort(two_sum.begin(),two_sum.end());
		for(int i=0;i<len;++i)
		{
			if(i!=0&&num[i]==num[i-1])
				continue;
			pair<vector<record>::iterator,vector<record>::iterator> t=equal_range(two_sum.begin(),two_sum.end(),record(-num[i]));
			for(vector<record>::iterator iter=t.first;iter!=t.second;++iter)
			{
				if(iter->pos1>i)
				{
					vector<int> temp;
					temp.push_back(num[i]);
					temp.push_back(num[iter->pos1]);
					temp.push_back(num[iter->pos2]);
					result.push_back(temp);
				}
			}
		}
		return result;
    }
};
*/
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<vector<int> > result;
        int len=num.size();
        for(int i=0;i<len-2;++i)
        {
          if(num[i]+num[i+1]+num[i+2]>0)
             break;
          if(i>0&&num[i]==num[i-1])
             continue;
          for(int j=i+1;j<len-1;++j)
          {
             if(num[i]+num[j]+num[j+1]>0)
               break;
             if(j>i+1&&num[j]==num[j-1])
               continue;
             int num_temp=-(num[i]+num[j]);
             if(num[j+1]>num_temp||num[len-1]<num_temp)
                  continue;
             int low_bound=j+1,high_bound=len-1;
             int median;
             while(low_bound<=high_bound)
             {
                 median=(low_bound+high_bound)>>1;
                 if(num[median]<num_temp)
                      low_bound=median+1;
                 else if(num[median]>num_temp)
                      high_bound=median-1;
                 else
                      break;
             }
             if(num[median]==num_temp)
             {
                 vector<int> temp;
                 temp.push_back(num[i]);
                 temp.push_back(num[j]);
                 temp.push_back(num[median]);
                 result.push_back(temp);
             }
          }
        }
        return result;
    }
};
int main()
{
	Solution s;
	int arr[]={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	int arr2[]={0,0,0};
	vector<vector<int> > result=s.threeSum(vector<int>(arr2,arr2+3));
	return 0;
}