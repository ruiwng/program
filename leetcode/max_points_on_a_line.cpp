#include  <vector>
#include  <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct comp_func
{
    bool operator()(const Point& lhs,const Point& rhs) const
    {
        if(lhs.x!=rhs.x)
            return lhs.x<rhs.x;
        return lhs.y<rhs.y;
    }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int len=points.size();
		if(len==1)
			return 1;
		int max_points=0;
        sort(points.begin(),points.end(),comp_func());
        len=points.size();
		for(int i=0;i<len-1;++i)
		{
            int num1=0;
            int current=1;
			for(int j=i+1;j<len;++j)
			{
                if(points[j].x==points[i].x&&points[j].y==points[i].y)
                {
                    ++num1;
                    continue;
                }
                int num2=0;
				int current_points=2;
				int temp_x=points[j].x-points[i].x;
                int temp_y=points[j].y-points[i].y;
				for(int k=j+1;k<len;++k)
				{
                    if(points[k].x==points[j].x&&points[k].y==points[j].y)
                    {
                        ++num2;
                        continue;
                    }
				    if(temp_x*(points[k].y-points[i].y)==temp_y*(points[k].x-points[i].x))
                            ++current_points;
				}
				if(current_points+num1+num2>max_points)
					max_points=current_points+num1+num2;
			}
            if(current+num1>max_points)
                max_points=current+num1;
		}
		return max_points;
    }
};
int main()
{
    vector<Point> point_array;
    point_array.push_back(Point(0,0));
    point_array.push_back(Point(0,0));
    Solution s;
    int result=s.maxPoints(point_array);
    return 0;
}
