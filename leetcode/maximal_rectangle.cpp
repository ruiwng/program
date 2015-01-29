#include  <string.h>
#include  <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
		int row=matrix.size();
		if(row==0)
			return 0;
		int column=matrix[0].size();
		if(column==0)
			return 0;
		int max_area=0;
		for(int i=0;i<row;++i)
		{
			if((row-i)*column<=max_area)//if the possible maximal rectangle of the left area is smaller than the current maximal rectangle, exit the loop
				break;
		    for(int j=0;j<column;++j)
			{
				if((row-i)*(column-j)<=max_area)//if the possible maximal rectangle of current point is smaller than the current maximal rectangle, exit the loop
					break;
				if(matrix[i][j]=='1')
				{
					int right_limit=column;
					for(int k=i;k<row;++k)
					{
						if(matrix[k][j]!='1')
							break;						
						for(int m=j;m<right_limit;++m)
						{
							if(matrix[k][m]!='1')//change the right boundary of the rectangle
							{
								right_limit=m;
								break;
							}
						}
						int temp=(k-i+1)*(right_limit-j);
						if(temp>max_area)
								max_area=temp;
					}
				}
			}
		}
	    return max_area;
    }
};

int main()
{
	Solution s;
	char* str[2]={"11","11"};
	vector<vector<char> > matrix;
	matrix.push_back(vector<char>(str[0],str[0]+2));
	matrix.push_back(vector<char>(str[1],str[1]+2));
	int result=s.maximalRectangle(matrix);
	return 0;
}