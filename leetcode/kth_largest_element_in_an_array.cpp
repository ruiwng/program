int kth;
int *arry;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void partition(int start,int end)
{
	if(start<end)
	{
		int index=start;
		for(int i=start;i<end;++i)
		{
			if(arry[i]>=arry[end])
				swap(&arry[index++],&arry[i]);
		}
		swap(&arry[index],&arry[end]);
		if(kth<index)
			partition(start,index-1);
		else if(kth>index)
			partition(index+1,end);
	}
	
}
int findKthLargest(int* nums, int numsSize, int k) {
    kth=k-1;
	arry=nums;
	partition(0,numsSize-1);
	return nums[k-1];
}

int main()
{
	int arry[]={3,2,1,5,6,4};
	int result=findKthLargest(arry,6,2);
	return 0;
}