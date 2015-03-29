#include  <stdlib.h>
#include  <string.h>

void merge(int A[], int m, int B[], int n) {
    int *p=(int*)malloc((m+n)*sizeof(int));
	int index=0;
	int index_a=0;
	int index_b=0;
	while(index_a<m&&index_b<n)
	{
		if(A[index_a]<=B[index_b])
			p[index++]=A[index_a++];
		else
			p[index++]=B[index_b++];
	}
	while(index_a<m)
		p[index++]=A[index_a++];
	while(index_b<n)
		p[index++]=B[index_b++];
	memcpy(A,p,(m+n)*sizeof(int));
	free(p);
}

int main()
{

}