 int climbStairs(int n) {
		if(n==1)
			return 1;
		if(n==2)
			return 2;
		int prev_two=1;
		int prev_one=2;
		for(int i=3;i<=n;++i)
		{
			int temp=prev_two+prev_one;
			prev_two=prev_one;
			prev_one=temp;
		}
		return prev_one;
}

int main()
{
	
}