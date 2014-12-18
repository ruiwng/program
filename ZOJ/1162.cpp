#include  <stdio.h>
#include  <string.h>
#include  <string>
#include  <vector>
#include  <queue>
using namespace std;

struct pos
{
    int x;
    int y;
    pos(int x1=0,int y1=0):x(x1),y(y1){
        
    }
    bool operator<(const pos& p) const
    {
        if(this->y!=p.y)
            return this->y<p.y;
        return this->x<x;
    }
};

int directions[4][2]=
    {
        {1,0},{-1,0},{0,1},{0,-1},
    };

int traversed_pos[10][15];

int bfs(const vector<string>& board_info,pos p)
{
    int result=0;
    char color=board_info[p.y][p.x];
    queue<pos> pos_queue;
    pos_queue.push(p);
    traversed_pos[p.x][p.y]=1;
    ++result;
    while(!pos_queue.empty())
    {
        pos pos_temp=pos_queue.front();
        pos_queue.pop();
        for(int m=0;m<4;++m)
        {
            pos pos_current(pos_temp.x+directions[m][0],pos_temp.y+directions[m][1]);
            if(pos_current.y>=0&&pos_current.y<board_info.size()&&pos_current.x>=0&&pos_current.x<board_info[pos_current.y].size()&&board_info[pos_current.y][pos_current.x]==color
               &&traversed_pos[pos_current.x][pos_current.y]==0)
            {
                    traversed_pos[pos_current.x][pos_current.y]=1;
                    pos_queue.push(pos_current);
                    ++result;
            }
         
        }
    }
    return result;
}


int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
		for(int m=0;m<n;++m)
		{
			if(m!=0)
				printf("\n");
			int num;
			scanf("%d",&num);
			for(int i=0;i<num;++i)
			{
				if(i!=0)
					printf("\n");
				vector<string>  board_info(15);
				for(int j=0;j<10;++j)
				{
					char str[20];
					scanf("%s",str);
					char* p=str;
					for(int k=0;k<15;++k)
						board_info[k].insert(0,1,*p++);
				}
				int num_balls=150;
				printf("Game %d:\n\n",i+1);
				int move_number=0;
				int all_scores=0;
				while(true)
				{
					memset(traversed_pos,0,sizeof(traversed_pos));
					pos global_min(10,15);
					int global_max=0;
					for(int j=0;j<15;++j)
					{
						if(board_info.size()<=j)
							break;
						for(int k=0;k<10;++k)
						{
							if(board_info[j].size()<=k)
								break;
							if(traversed_pos[k][j]==1)
								continue;
							int current_number=bfs(board_info,pos(k,j));
							if(current_number>global_max||(current_number==global_max&&pos(k,j)<global_min))
							{
								global_max=current_number;
								global_min=pos(k,j);
							}
						}
					}
					if(global_max==1)
						break;
					num_balls-=global_max;
					int current_score=(global_max-2)*(global_max-2);
					all_scores+=current_score;
					printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",++move_number,
						global_min.x+1,global_min.y+1,global_max,board_info[global_min.y][global_min.x],current_score);
					memset(traversed_pos,0,sizeof(traversed_pos));
					bfs(board_info,global_min);
					int length=board_info.size();
					for(int j=0;j<length;++j)
					{
						string& temp=board_info[j];
						int length2=temp.size();
						int erased_number=0;
						for(int k=0;k<temp.size();)
						{
							if(traversed_pos[k+erased_number][j]==1)
							{
								temp.erase(temp.begin()+k);
								++erased_number;
							}
							else
								++k;
						}
					}
					for(int j=0;j<board_info.size();)
					{
						if(board_info[j].empty())
							board_info.erase(board_info.begin()+j);
						else
							++j;
					}
					if(board_info.empty())
						break;
				}
				if(board_info.empty())
					all_scores+=1000;
				printf("Final score: %d, with %d balls remaining.\n",all_scores,num_balls);

			}      
		}
       
    }
    return 0;
}
