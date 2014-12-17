#include  <stdio.h>
#include  <stdlib.h>
#include  <algorithm>
using namespace std;
int main()
{
	float f[3][3];
	float max[3];
	for(int i=0;i<3;i++)
	{
		scanf("%f %f %f",&f[i][0],&f[i][1],&f[i][2]);
	}
	for(int i=0;i<3;i++)
	{
		if(f[i][0]>=f[i][1]&&f[i][0]>=f[i][2])
		{
			max[i]=f[i][0];
			printf("W ");
		}
		else if(f[i][1]>=f[i][0]&&f[i][1]>=f[i][2])
		{
			max[i]=f[i][1];
			printf("T ");
		}
		else
		{
			max[i]=f[i][2];
			printf("L ");
		}
	}
	printf("%.2f\n",(max[0]*max[1]*max[2]*0.65-1)*2);
	return 0;
}