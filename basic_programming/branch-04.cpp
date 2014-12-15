#include  <stdio.h>

int main()
{
	double distance;
	int waiting_time;
	while(scanf("%lf %d",&distance,&waiting_time)!=EOF)
	{
		double fee;
		if(distance<=3)
			fee=10;
		else if(distance>3&&distance<=10)
			fee=10+(distance-3)*2;
		else
			fee=24+3*(distance-10);

		fee+=waiting_time/5*2;

		int temp1=fee;
		double temp2=fee-temp1;
		if(temp2>=0.5)
		   printf("%d\n",temp1+1);
		else
			printf("%d\n",temp1);
	}
	return 0;
}