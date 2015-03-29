bool canJump(int A[], int n) {
	if(n==1)
		return true;
    int index=0;
	int end=0;
	while(index<=end)
	{
		if(end<A[index]+index)
			end=A[index]+index;
		if(end>=n-1)
			return true;
		++index;
	}
	return false;
}

int main()
{

}