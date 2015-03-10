#include  <stdio.h>

const char *cards[]=
{
	"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
	"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
	"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
	"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
	"J1","J2"
};

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int init_state[54];
		int auxilary_state[54];
		for(int i=0;i<54;++i)
			init_state[i]=i;
		int shuffle[54];
		for(int i=0;i<54;++i)
			scanf("%d",&shuffle[i]);
		int *p=init_state,*q=auxilary_state;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<54;++j)
			  q[shuffle[j]-1]=p[j];
			int *temp=q;
			q=p;
			p=temp;
		}
		for(int i=0;i<54;++i)
			printf("%s%c",cards[p[i]],i==53?'\n':' ');
	}
	return 0;
}