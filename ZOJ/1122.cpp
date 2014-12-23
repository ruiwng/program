#include  <stdio.h>
#include  <vector>
using namespace std;
struct tim
{
    double hour;
    double minute;
    tim(double h=0,double m=0):hour(h),minute(m){
        
    }
    bool operator<(const tim& t) const
    {
        if(this->hour!=t.hour)
            return this->hour<t.hour;
        return this->minute<t.minute;
    }
};

int main()
{
    printf("Program 3 by team X\n");
    printf("Initial time  Final time  Passes\n");
    freopen("test.txt","r",stdin);
    tim start,end;
    vector<tim> tim_array;
    for(int i=0;i<24;++i)
    {
        if(i==11||i==23)
            continue;
        if(i<12)
            tim_array.push_back(tim(i,i*60/11));
        else
            tim_array.push_back(tim(i,(i-12)*60/11));
    }
    while(scanf("%lf%lf%lf%lf",&start.hour,&start.minute,&end.hour,&end.minute)!=EOF)
    {
        int num=0;
        tim t=end;
        if(t<start)
            t.hour+=12;
        int j=0;
        for(;j<24;++j)
        {
            if(start<tim_array[j])
                break;
        }
        while(tim_array[j]<t&&j<24)
        {
            ++num;
            ++j;
        }
            
        printf("       %02d:%02d       %02d:%02d     %3d\n",static_cast<int>(start.hour),static_cast<int>(start.minute),
               static_cast<int>(end.hour),static_cast<int>(end.minute),num);
    }
    printf("End of program 3 by team X\n");
    return 0;
}
