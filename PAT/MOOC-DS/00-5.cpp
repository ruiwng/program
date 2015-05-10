#include  <stdio.h>

const char* card_array[54]=
{
	"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
	"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
	"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
	"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
	"J1","J2"
};

int main()
{
	int arry[2][54];
	int operation[54];
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<54;++i)
		{
			arry[0][i]=i;
			scanf("%d",&operation[i]);
		}
		int *p=arry[0];
		int *q=arry[1];
		while(n--!=0)
		{
			for(int i=0;i<54;++i)
				q[operation[i]-1]=p[i];
			int *temp=p;
			p=q;
			q=temp;
		}
		for(int i=0;i<54;++i)
			printf("%s%c",card_array[p[i]],i==53?'\n':' ');
	}
	return 0;
}