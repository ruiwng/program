#include  <stdlib.h>

int *searchRange(int A[], int n, int target) {
	int *result=(int*)malloc(2*sizeof(int));
	result[0]=-1;
	result[1]=-1;
	int lower=0,upper=n-1;
	int median;
	while(lower<=upper)
	{
		median=(lower+upper)>>1;
		if(A[median]<target)
			lower=median+1;
		else if(A[median]>target)
			upper=median-1;
		else
		{
			int left=median;
			while(left-1>=0&&A[left-1]==target)
				--left;
			int right=median;
			while(right+1<n&&A[right+1]==target)
				++right;
			result[0]=left;
			result[1]=right;
			break;
		}
	}
	return result;
}

int main()
{
	int A[]={5,7,7,8,8,10};
	int* r=searchRange(A,5,8);
	return 0;
}