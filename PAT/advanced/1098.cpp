#include  <stdio.h>

int init_arry[100];
int median_arry[100];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&init_arry[i]);
		for(int i=0;i<n;++i)
			scanf("%d",&median_arry[i]);
		int index=1;
		while(index<=n-1&&median_arry[index]>=median_arry[index-1])
			++index;
		int pos=index;
		while(index<=n-1&&init_arry[index]==median_arry[index])
			++index;	
		if(index==n)
		{
			printf("Insertion Sort\n");
			int temp=median_arry[pos];
			int j=pos-1;
			for(;j>=0&&median_arry[j]>temp;--j)
				median_arry[j+1]=median_arry[j];
			median_arry[j+1]=temp;
		}
		else
		{
			printf("Heap Sort\n");
			int pos=n-1;
			while(median_arry[pos]>=median_arry[0])
				--pos;
			int temp=median_arry[0];
			median_arry[0]=median_arry[pos];
			median_arry[pos]=temp;
			--pos;
			int k=0;
			while(k<=pos/2)
			{
				int left=2*k+1;
				if(left<pos&&median_arry[left]<median_arry[left+1])
					++left;
				if(median_arry[k]<median_arry[left])
				{
					int t=median_arry[k];
					median_arry[k]=median_arry[left];
					median_arry[left]=t;
					k=left;
				}
				else
					break;
			}
		}
		for(int i=0;i<n;++i)
			printf("%d%c",median_arry[i],i==n-1?'\n':' ');
	}
	return 0;
}