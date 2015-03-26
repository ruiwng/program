int removeElement(int A[], int n, int elem) {
    int index=0;
	int pos=0;
	while(index<n)
	{
		if(A[index]!=elem)
			A[pos++]=A[index];
		++index;
	}
	return pos;
}

int main()
{

}