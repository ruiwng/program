#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <functional>
using namespace std;

struct block
{
    int length;
    int width;
    int height;
    int maximum_height;
    block& operator=(const block& b)
    {
        this->length=b.length;
        this->width=b.width;
        this->height=b.height;
        return *this;
    }
    block(int l=0,int w=0,int h=0,int m=0):length(l),width(w),height(h),maximum_height(m){
    
    }
    bool operator>(const block& b) const
    {
        if(this->length!=b.length)
            return this->length>b.length;
        if(this->width!=b.width)
            return this->width>b.width;
        return this->height>b.height;
    }
};

int main()
{
    int n;
    int case_number=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        vector<block> blocks_array;
        blocks_array.reserve(3*n);
        for(int i=0;i<n;++i)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a>=b)
                blocks_array.push_back(block(a,b,c));
            else
                blocks_array.push_back(block(b,a,c));
            if(a>=c)
                blocks_array.push_back(block(a,c,b));
            else
                blocks_array.push_back(block(c,a,b));
            if(b>=c)
                blocks_array.push_back(block(b,c,a));
            else
                blocks_array.push_back(block(c,b,a));
        }

        sort(blocks_array.begin(),blocks_array.end(),greater<block>());
        int length=blocks_array.size();
        int maximum_height=0;
        for(int i=0;i<length;++i)
        {
            blocks_array[i].maximum_height=blocks_array[i].height;
            for(int j=i-1;j>=0;--j)
            {
                if(blocks_array[i].length<blocks_array[j].length&&blocks_array[i].width<blocks_array[j].width)
                {
                    if(blocks_array[j].maximum_height+blocks_array[i].height>blocks_array[i].maximum_height)
                        blocks_array[i].maximum_height=blocks_array[j].maximum_height+blocks_array[i].height;
                }
                if(blocks_array[i].maximum_height>maximum_height)
                    maximum_height=blocks_array[i].maximum_height;
            }
        }
        printf("Case %d: maximum height = %d\n",++case_number,maximum_height);
    }
    return 0;
}
