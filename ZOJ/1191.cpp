#include  <stdio.h>
#include  <string.h>
#include  <queue>
#include  <algorithm>
using namespace std;
char picture[52][52];
char tag[52][52];
int w,h;

struct pos
{
    int x;
    int y;
    pos(int x1=0,int y1=0):x(x1),y(y1){
        
    }
};

int directions[4][2]=
    {
        {1,0},{-1,0},{0,1},{0,-1}
    };

int layer_traverse(int x,int y)
{
    tag[x][y]=1;
    queue<pos> pos_queue;
    pos_queue.push(pos(x,y));
    vector<pos> dots_array;
    while(!pos_queue.empty())
    {
        pos t=pos_queue.front();
        if(picture[t.x][t.y]=='X')
            dots_array.push_back(t);
        pos_queue.pop();
        for(int i=0;i<4;++i)
        {
            pos temp(t.x+directions[i][0],t.y+directions[i][1]);
            if(temp.x>=0&&temp.x<h&&temp.y>=0&&temp.y<w&&picture[temp.x][temp.y]!='.'&&tag[temp.x][temp.y]==0)
            {
                tag[temp.x][temp.y]=1;
                pos_queue.push(temp);
            }
        }
    }
    int len=dots_array.size();
    int number=0;
    for(int i=0;i<len;++i)
    {
        const pos& p=dots_array[i];
        if(tag[p.x][p.y]==2)
            continue;
        ++number;
        tag[p.x][p.y]=2;
        pos_queue.push(p);
        while(!pos_queue.empty())
        {
            pos t=pos_queue.front();
            pos_queue.pop();
            for(int j=0;j<4;++j)
            {
                pos temp(t.x+directions[j][0],t.y+directions[j][1]);
                if(temp.x>=0&&temp.x<h&&temp.y>=0&&temp.y<w&&picture[temp.x][temp.y]=='X'&&tag[temp.x][temp.y]==1)
                {
                    tag[temp.x][temp.y]=2;
                    pos_queue.push(temp);
                }
            }
        }
    }
    return number;
}
int main()
{

    int throw_number=0;
    freopen("test.txt","r",stdin);
    while(scanf("%d%d",&w,&h)!=EOF)
    {
        if(w==0&&h==0)
            break;
        for(int i=0;i<h;++i)
            scanf("%s",picture[i]);
        memset(tag,0,sizeof(tag));
        vector<int> number_dots;
        for(int i=0;i<h;++i)
        {
            for(int j=0;j<w;++j)
            {
                if(picture[i][j]!='.'&&tag[i][j]==0)
                    number_dots.push_back(layer_traverse(i,j));
            }
        }
        sort(number_dots.begin(),number_dots.end());
        printf("Throw %d\n",++throw_number);
        int len=number_dots.size();
        for(int i=0;i<len;++i)
            printf("%d%c",number_dots[i],i==len-1?'\n':' ');
        printf("\n");
    }
    return 0;
}
