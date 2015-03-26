
int removeDuplicates(int A[], int n) {
	if(n==0)
		return 0;
    int index=1;
	int pos=0;
	while(index<n)
	{
		if(A[pos]!=A[index])
			A[++pos]=A[index];
		++index;
	}
	return pos+1;
}

int main()
{

}