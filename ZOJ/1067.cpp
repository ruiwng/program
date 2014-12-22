#include  <stdio.h>
#include  <math.h>

#define MAX_DISTANCE     10000

struct color
{
	int red;
	int green;
	int blue;
	color(int r=0,int g=0,int b=0):red(r),green(g),blue(b){}
};

color all_colors[16];

int main()
{
	for(int i=0;i<16;++i)
		scanf("%d%d%d",&all_colors[i].red,&all_colors[i].green,&all_colors[i].blue);
	color target;
	while(scanf("%d%d%d",&target.red,&target.green,&target.blue)!=EOF)
	{
		if(target.red==-1&&target.green==-1&&target.blue==-1)
			break;
		double length=MAX_DISTANCE;
		int index;
		for(int i=0;i<16;++i)
		{
			double temp=sqrt(static_cast<double>((all_colors[i].red-target.red)*(all_colors[i].red-target.red)
				+(all_colors[i].green-target.green)*(all_colors[i].green-target.green)+(all_colors[i].blue-target.blue)*(all_colors[i].blue-target.blue)));
			if(temp<length)
			{
				length=temp;
				index=i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",target.red,target.green,target.blue,
			all_colors[index].red,all_colors[index].green,all_colors[index].blue);
	}
	return 0;
}