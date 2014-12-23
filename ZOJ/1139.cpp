#include  <stdio.h>
#include  <vector>
using namespace std;

struct rectangle
{
    int xmin;
    int xmax;
    int ymin;
    int ymax;
    rectangle(int xi=0,int xa=0,int yi=0,int ya=0):xmin(xi),xmax(xa),ymin(yi),ymax(ya){
        
    }
};

inline bool is_covered(const rectangle& lhs,const rectangle& rhs)
{
    return lhs.xmin<=rhs.xmin&&lhs.xmax>=rhs.xmax&&lhs.ymin<=rhs.ymin&&lhs.ymax>=rhs.ymax;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        vector<rectangle> rectangle_array;
        rectangle_array.reserve(n);
        for(int i=0;i<n;++i)
        {
            rectangle temp;
            scanf("%d%d%d%d",&temp.xmin,&temp.xmax,&temp.ymin,&temp.ymax);
            rectangle_array.push_back(temp);
        }
        int n_cover=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(j==i)
                    continue;
                if(is_covered(rectangle_array[j],rectangle_array[i]))
                {
                    ++n_cover;
                    break;
                }
            }
        }
        printf("%d\n",n_cover);
    }
    return 0;
}
