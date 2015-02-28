#include  <stdio.h>
#include  <string.h>

struct piece
{
	int row;
	int column;
};

piece piece_array[5];
char shape[5][4][5];
char square[4][4];
int piece_number;
bool success;

bool is_suitable(int x,int y,int piece_num)//whether the current piece is suitable to be placed in current position, if this is the case, place it.
{
	int r=piece_array[piece_num].row;
	int c=piece_array[piece_num].column;
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			if(shape[piece_num][i][j]!='0')
			{
				if(x+i>=4||y+j>=4||square[x+i][y+j]!='0')
					return false;
			}
				
		}
	}
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			if(shape[piece_num][i][j]!='0')
				square[x+i][y+j]=piece_num+'1';
		}
	}
	return true;
}
void erase_piece(int x,int y,int piece_num)
{
	int r=piece_array[piece_num].row;
	int c=piece_array[piece_num].column;
	for(int i=0;i<r;++i)
	{
		for(int j=0;j<c;++j)
		{
			if(shape[piece_num][i][j]!='0')
				square[x+i][y+j]='0';
		}
	}
}
void recurse(int index)
{
	if(index==piece_number)
	{
		success=true;
		for(int i=0;i<4;++i)
		{
			for(int j=0;j<4;++j)
				printf("%c",square[i][j]);
			printf("\n");
		}
	}
	else
	{
		for(int i=0;!success&&i<=4-piece_array[index].row;++i)
		{
			for(int j=0;!success&&j<=4-piece_array[index].column;++j)
			{
				if(is_suitable(i,j,index))
				{
				   recurse(index+1);
				   erase_piece(i,j,index);
				}
			}
		}
	}
}

int main()
{
    bool first=true;
	memset(square,'0',sizeof(square));
	while(scanf("%d",&piece_number)!=EOF&&piece_number)
	{
		if(first)
			first=false;
		else
			printf("\n");
		int area=0;//area of the square
		for(int i=0;i<piece_number;++i)
		{
			scanf("%d%d",&piece_array[i].row,&piece_array[i].column);
			for(int j=0;j<piece_array[i].row;++j)
			{
			    scanf("%s",shape[i][j]);
				for(int k=0;k<piece_array[i].column;++k)
					if(shape[i][j][k]=='1')
						++area;
			}
		}
		if(16!=area)
			printf("No solution possible\n");
		else
		{
			success=false;
			recurse(0);
		    if(!success)
			printf("No solution possible\n");
		}	
	}
	return 0;
}