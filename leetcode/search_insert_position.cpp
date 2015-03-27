int searchInsert(int A[], int n, int target) {
    int lower=0,upper=n-1;
	int median;
	while(lower<=upper)
	{
		median=(lower+upper)>>1;
		if(A[median]>target)
			upper=median-1;
		else if(A[median]<target)
			lower=median+1;
		else
			break;
	}
	++median;
	while(median>0&&A[median-1]>=target)
		--median;
	return median;
}

int main()
{
	int A[]={1,3,5,6};
	int pos=searchInsert(A,4,0);
	return 0;
}