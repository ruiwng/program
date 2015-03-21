#include  <stdio.h>

int arry[101];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			bool is_binary=true;
			for(int j=0;j<m;++j)
		    {
				int temp;
				scanf("%d",&temp);
				if(is_binary)
				{
				   for(int k=1;k<j;++k)
				   {
					   if(!((arry[k]>arry[k-1]&&temp>arry[k-1])||(arry[k]<arry[k-1]&&temp<arry[k-1])))
					   {
						   is_binary=false;
						   break;
					   }
				   }
				   if(is_binary)
					   arry[j]=temp;
				}
			}
			printf("%s\n",is_binary?"YES":"NO");
		}
		
	}
	return 0;
}