#include  <vector>
#include  <algorithm>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
		int m=dungeon.size();
		int n=dungeon[0].size();

		vector<vector<int> > dp(m,vector<int>(n));
		dp[m-1][n-1]=max(0-dungeon[m-1][n-1],0);

		for(int i=m-2;i>=0;--i)
			dp[i][n-1]=max(dp[i+1][n-1]-dungeon[i][n-1],0);

		for(int i=n-2;i>=0;--i)
			dp[m-1][i]=max(dp[m-1][i+1]-dungeon[m-1][i],0);

		for(int i=m-2;i>=0;--i)
			for(int j=n-2;j>=0;--j)
				dp[i][j]=max(min(dp[i][j+1],dp[i+1][j])-dungeon[i][j],0);

		return dp[0][0]+1;
	}
};

int main()
{
	vector<vector<int> > dungeon(3,vector<int>(3));
	dungeon[0][0]=-2;
	dungeon[0][1]=-3;
	dungeon[0][2]=3;
	dungeon[1][0]=-5;
	dungeon[1][1]=-10;
	dungeon[1][2]=1;
	dungeon[2][0]=10;
	dungeon[2][1]=30;
	dungeon[2][2]=-5;
	Solution s;
	int result=s.calculateMinimumHP(dungeon);
	return 0;
}

