#include  <stdio.h>
#include  <string.h>

int directions[5][2]=
{
	{0,0},{-1,0},{1,0},{0,-1},{0,1}
};
int current_state[5][6];

inline void change_state(int x,int y)
{
	for(int i=0;i<5;++i)
	{
		int x_temp=x+directions[i][0];
		int y_temp=y+directions[i][1];
		if(x_temp>=0&&x_temp<5&&y_temp>=0&&y_temp<6)
		{
			if(current_state[x_temp][y_temp]==0)
				current_state[x_temp][y_temp]=1;
			else
				current_state[x_temp][y_temp]=0;
		}
	}
}

int main()
{
	int puzzle_number;
	while(scanf("%d",&puzzle_number)!=EOF)
	{
		for(int i=0;i<puzzle_number;++i)
		{
			int init_state[5][6];
			for(int j=0;j<5;++j)
				for(int k=0;k<6;++k)
					scanf("%d",&init_state[j][k]);

			printf("PUZZLE #%d\n",i+1);
			int button_state[5][6];
			memset(button_state[0],0,sizeof(button_state[0]));
			while(true)
			{
				// try all the statement of the first row, and change the statement of subsequent rows according to the first row.
				memcpy(current_state,init_state,sizeof(current_state));
				for(int j=0;j<6;++j)
				{
					if(button_state[0][j]==1)
						change_state(0,j);
				}
				for(int j=1;j<5;++j)
				{
					for(int k=0;k<6;++k)
					{
						if(current_state[j-1][k]==1)
						{
							button_state[j][k]=1;
							change_state(j,k);
						}
						else
							button_state[j][k]=0;
					}
				}
				bool succeed=true;
				for(int j=0;j<6;++j)
				{
					if(current_state[4][j]==1)
					{
						succeed=false;
						break;
					}
				}
				if(succeed)
				{
					for(int j=0;j<5;++j)
					{
						for(int k=0;k<6;++k)
							printf("%d%c",button_state[j][k],k==5?'\n':' ');
					}
					break;
				}
				int m=5;
				while(m>=0)
				{
					if(++button_state[0][m]==1)
						break;
					else
					{
						button_state[0][m]=0;
						--m;
					}
				}
				if(m<0)
					break;
			}
		}
	}
	return 0;
}