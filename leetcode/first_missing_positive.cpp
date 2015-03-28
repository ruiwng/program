int firstMissingPositive(int A[], int n) {
    for(int i=0;i<n;++i)
		{
			if(A[i]<=0)
				continue;
			int num=A[i];
			while(num>0&&num<=n&&num!=A[num-1])
			{
				int temp=A[num-1];
				A[num-1]=num;
				num=temp;
			}
		}
		for(int i=0;i<n;++i)
		{
			if(A[i]!=i+1)
				return i+1;
		}
		return n+1;
}

int main()
{
	
}