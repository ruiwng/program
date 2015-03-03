#include  <stdio.h>
#include  <math.h>
#include  <vector>
#include  <algorithm>
using namespace std;

const double PI=3.1415926535898;

int main()
{
	double t_x,t_y,radius;
	while(scanf("%lf%lf%lf",&t_x,&t_y,&radius)!=EOF&&radius>=0.0)
	{
		int n;
		scanf("%d",&n);
		double temp=radius*radius;
		vector<double> angle_array;
		while(--n>=0)
		{
			double x,y;
			scanf("%lf%lf",&x,&y);
			if(((x-t_x)*(x-t_x)+(y-t_y)*(y-t_y))<=temp)
			{
				double k=atan((y-t_y)/(x-t_x));
				if(x<t_x&&y>=t_y)
					k+=PI;
				else if(x<t_x&&y<t_y)
					k-=PI;
				angle_array.push_back(k);
			}
		}
		sort(angle_array.begin(),angle_array.end());
		int max_num=0;
		for(vector<double>::iterator iter=angle_array.begin();iter!=angle_array.end();++iter)
		{
			double t=*iter+PI;
			if(t<=PI)
			{
				vector<double>::iterator iter_temp=upper_bound(iter,angle_array.end(),t);
				int m=iter_temp-iter;
				if(m>max_num)
					max_num=m;
			}
			else
			{
				t-=2*PI;
				vector<double>::iterator iter_temp=upper_bound(angle_array.begin(),iter,t);
				int m=iter_temp-angle_array.begin()+(angle_array.end()-iter);
				if(m>max_num)
					max_num=m;
			}
		}
		printf("%d\n",max_num);
	}
	return 0;
}