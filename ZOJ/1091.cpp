#include  <stdio.h>
#include  <string.h>
#include  <queue>
using namespace std;
int records[9][9];

struct pos
{
    int x;
    int y;
    int step;
    pos(int x1=0,int y1=0,int s=0):x(x1),y(y1),step(s){
    }
    bool operator==(const pos& p) const
    {
        return this->x==p.x&&this->y==p.y;
    }
};

int directions[8][2]=
    {
        {2,1},{2,-1},{1,2},{1,-2},
        {-2,1},{-2,-1},{-1,2},{-1,-2}
    };
int main()
{
    char str1[3],str2[3];
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        pos start,end;
        memset(records,0,sizeof(records));
        start.x=str1[0]-'a';
        start.y=str1[1]-'1';
        end.x=str2[0]-'a';
        end.y=str2[1]-'1';

        queue<pos> pos_queue;
        pos_queue.push(start);
        records[start.x][start.y]=1;
    
        while(!pos_queue.empty())
        {
            pos pos_temp=pos_queue.front();
            pos_queue.pop();
            if(pos_temp==end)
            {
                printf("To get from %s to %s takes %d knight moves.\n",str1,str2,pos_temp.step);
                break;
            }
            int current_steps=pos_temp.step+1;
            
            for(int i=0;i<8;++i)
            {
                pos pos_current(pos_temp.x+directions[i][0],pos_temp.y+directions[i][1],current_steps);
                
                if(pos_current.x<0||pos_current.x>7||pos_current.y<0||pos_current.y>7||records[pos_current.x][pos_current.y]==1)
                    continue;
              
                records[pos_current.x][pos_current.y]=1;
                pos_queue.push(pos_current);     
            }
        }

     }
    return 0;
}
