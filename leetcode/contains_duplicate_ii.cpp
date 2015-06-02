/*************************************************************************
	> File Name: contains_duplicate_ii.cpp
	> Author: ruiwng
	> Mail: ruiwng@zju.edu.cn 
	> Created Time: Tue 02 Jun 2015 10:09:09 AM CST
 ************************************************************************/
#include  <stdio.h>
#include  <vector>
#include  <queue>
#include  <unordered_set>
using namespace std;

class Solution
{
public:
	bool containsNearbyDuplicate(vector<int>& nums,int k)
	{
		unordered_set<int> traversed_set;
		queue<int> traversed_queue;
		int len=nums.size();
		for(int i=0;i<len;++i)
		{
			if(traversed_set.find(nums[i])!=traversed_set.end())
				return true;
			traversed_queue.push(nums[i]);
			traversed_set.insert(nums[i]);
			
			while(!traversed_queue.empty()&&traversed_queue.size()>k)
			{
				traversed_set.erase(traversed_queue.front());
				traversed_queue.pop();
			}
		}
		return false;
	}
};

int main()
{
}
