#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main()
{
	int n;
	int num[5];
	while(scanf("%d",&n)!=EOF)
	{
		bool exist=false;
		int index=0;
		int count=0;
		memset(num,'\0',5*sizeof(int));
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			switch(x%5)
			{
			case 0:
				if(x%2==0)
					num[0]+=x;
				break;
			case 1:
				exist=true;
				if((++index)%2==1)
					num[1]+=x;
				else
					num[1]-=x;
				break;
			case 2:
				num[2]++;
				break;
			case 3:
				count++;
				num[3]+=x;
				break;
			case 4:
				if(x>num[4])
					num[4]=x;
				break;
			}
		}
		if(num[0]!=0)
			printf("%d ",num[0]);
		else
			printf("N ");
		if(num[1]!=0||exist==true)
			printf("%d ",num[1]);
		else
			printf("N ");
		if(num[2]!=0)
			printf("%d ",num[2]);
		else
			printf("N ");
		if(num[3]!=0)
			printf("%0.1f ",static_cast<float>(num[3])/count);
		else
			printf("N ");
		if(num[4]!=0)
			printf("%d\n",num[4]);
		else
			printf("N\n");
	}
	return 0;
}