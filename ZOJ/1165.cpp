#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <algorithm>
using namespace std;

struct pos
{
    int x;
    int y;
    pos(int x1=0,int y1=0):x(x1),y(y1){
        
    }
    bool operator==(const pos& p) const
    {
        return this->x==p.x&&this->y==p.y;
    }
    bool operator<(const pos& p) const
    {
        if(this->x!=p.x)
            return this->x<p.x;
        return this->y<p.y;
    }
};

int main()
{
    char str[1000];
    vector<vector<pos> > line_array;
    vector<pos> pos_array;
    while(fgets(str,1000,stdin)!=NULL)
    {
        char* p=str;
        while(*p==' ')
            ++p;
        pos temp;
        pos p1,p2;
        bool flag=false;
        while(sscanf(p,"%d%d",&temp.x,&temp.y)==2)
        {
            if(temp.x==0&&temp.y==0)
            {
                flag=true;
                break;
            }
            pos_array.push_back(temp);
            p=strchr(p,' ');
            while(*p==' ')
                ++p;
            p=strchr(p,' ');
            if(p==NULL)
                break;
            while(*p==' ')
                ++p;
        }
        if(flag&&pos_array.empty())
            break;
        if(flag)
        {
            sort(pos_array.begin(),pos_array.end());
            int len=pos_array.size();
            for(int i=0;i<len-1;++i)
            {
               for(int j=i+1;j<len;++j)
               {
                  int line_len=line_array.size();
                  bool success=false;
                  for(int k=0;k<line_len;++k)
                  {
                    vector<pos>::iterator iter1=lower_bound(line_array[k].begin(),line_array[k].end(),pos_array[i]);
                    vector<pos>::iterator iter2=lower_bound(line_array[k].begin(),line_array[k].end(),pos_array[j]);
                    if(iter1!=line_array[k].end()&&*iter1==pos_array[i]&&iter2!=line_array[k].end()&&*iter2==pos_array[j])
                    {
                        success=true;
                        break;
                    }
                  }
                  if(success)
                    continue;
                  vector<pos> current_line;
                  current_line.push_back(pos_array[i]);
                  current_line.push_back(pos_array[j]);
                  int temp_x=pos_array[j].x-pos_array[i].x;
                  int temp_y=pos_array[j].y-pos_array[i].y;
                  for(int k=j+1;k<len;++k)
                  {
                    if(temp_x*(pos_array[k].y-pos_array[i].y)==temp_y*(pos_array[k].x-pos_array[i].x))
                        current_line.push_back(pos_array[k]);
                  }
                  if(current_line.size()>2)
                    line_array.push_back(current_line);
                }
             }

            int length=line_array.size();
            if(length==0)
                printf("No lines were found\n");
            else
            {
                printf("The following lines were found:\n");
                for(int i=0;i<length;++i)
                {
                    const vector<pos>& current_line=line_array[i];
                    int point_len=current_line.size();
                    for(int j=0;j<point_len;++j)
                        printf("(%4d,%4d)",current_line[j].x,current_line[j].y);
                    printf("\n");
                }
            }
            pos_array.clear();
            line_array.clear();
         }      
    }
    return 0;
}
