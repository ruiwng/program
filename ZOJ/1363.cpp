#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	int C;
	while(scanf("%d",&C)!=EOF&&C)
	{
		int N,M;
		scanf("%d%d",&N,&M);
		if(M>C)
		{
			printf("0.000\n");
			continue;
		}
		vector<double> current_state(C+1,0);
		current_state[0]=1.0;
		vector<double> auxilary_state;
		int temp=min(N,C*5);
		if((N-temp)%2==1)
			++temp;
		for(int i=0;i<temp;++i)
		{
			auxilary_state.assign(C+1,0.0);
			for(int j=0;j<=C;++j)
			{
				if(j!=0)
					auxilary_state[j-1]+=current_state[j]*j/C;
				if(j!=C)
				    auxilary_state[j+1]+=current_state[j]*(C-j)/C;
			}
			current_state.swap(auxilary_state);
		}
		printf("%.3lf\n",current_state[M]);
	}
	return 0;
}