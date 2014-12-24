#include  <stdio.h>
#include  <vector>
#include  <map>
#include  <set>
#include  <string>
#include  <functional>
#include  <algorithm>
using namespace std;

struct pos
{
    int y;
    char tag;
    pos(int y1=0,char t='0'):y(y1),tag(t){
        
    }
    bool operator>(const pos& p) const
    {
        return this->y>p.y;
    }
};

int main()
{
    int n;
    int set_number=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        map<int,vector<pos> > point_array;
        for(int i=0;i<n;++i)
        {
            char str[3];
            int x,y;
            scanf("%s %d %d",str,&x,&y);
            point_array[x].push_back(pos(y,str[0]));
        }

        for(map<int,vector<pos> >::iterator iter=point_array.begin();iter!=point_array.end();++iter)
            sort(iter->second.begin(),iter->second.end(),greater<pos>());
        
        vector<string> rectangle_array;
        
        for(map<int,vector<pos> >::iterator iter=point_array.begin();iter!=point_array.end();++iter)
        {
            const vector<pos>& arry1=iter->second;
            int len1=arry1.size();
            if(len1==1)
                continue;
            map<int,vector<pos> >::iterator iter1=iter;
            ++iter1;
            for(;iter1!=point_array.end();++iter1)
            {
                const vector<pos>& arry2=iter1->second;
                int len2=arry2.size();
                if(len2==1)
                    continue;
                for(int i=0;i<len1-1;++i)
                {
                    for(int j=i+1;j<len1;++j)
                    {
                        vector<pos>::const_iterator iter_temp1=lower_bound(arry2.begin(),arry2.end(),pos(arry1[i]),greater<pos>());
                        vector<pos>::const_iterator iter_temp2=lower_bound(arry2.begin(),arry2.end(),pos(arry1[j]),greater<pos>());
                        if(iter_temp1!=arry2.end()&&iter_temp1->y==arry1[i].y
                           &&iter_temp2!=arry2.end()&&iter_temp2->y==arry1[j].y)
                        {
                            string str;
                            str.push_back(arry1[i].tag);
                            str.push_back(iter_temp1->tag);
                            str.push_back(iter_temp2->tag);
                            str.push_back(arry1[j].tag);
                            rectangle_array.push_back(str);
                        }
                    }
                }
            }
        }

        sort(rectangle_array.begin(),rectangle_array.end());
        printf("Point set %d:",++set_number);
        if(rectangle_array.empty())
            printf(" No rectangles\n");
        else
        {
            printf("\n");
            int len=rectangle_array.size();
            for(int i=0;i<len;++i)
            {
                printf(" %s",rectangle_array[i].c_str());
                if((i+1)%10==0)
                    printf("\n");
            }
            if(len%10!=0)
                printf("\n");
        }
    }
    return 0;
}
