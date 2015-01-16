class Solution {
public:
    int trap(int A[], int n) {
		int start=0;
		int water_trapped=0;
		while(start<n-2)
		{
			int j=start+1;
			int current_trap=0;
			int max_elevation=j;
			int temp=0;
			while(j<=n-1&&A[start]>A[j])
			{
				current_trap+=A[start]-A[j];
				temp+=A[start]-A[j];
				if(A[j]>=A[max_elevation])
				{
					temp=0;
					max_elevation=j;
				}
				++j;
			}
			if(j!=n)
			{
				water_trapped+=current_trap;
				start=j;
			}
			else
			{
				water_trapped+=current_trap-(max_elevation-start)*(A[start]-A[max_elevation])-temp;
				start=max_elevation;
			}

		}
		return water_trapped;
    }
};

int main()
{
	int arry[]={2,0,2};
	Solution s;
	int result=s.trap(arry,3);
	return 0;
}