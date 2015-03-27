#include  <string.h>

bool isValidSudoku(char board[9][9]) {
    int arr[9];
        for(int i=0;i<9;++i)
		{
			memset(arr,0,sizeof(arr));
			for(int j=0;j<9;++j)
			{
				if(board[i][j]=='.')
					continue;
				if(arr[board[i][j]-'1']==1)
					return false;
				arr[board[i][j]-'1']=1;
			}
		}
		for(int i=0;i<9;++i)
		{
			memset(arr,0,sizeof(arr));
			for(int j=0;j<9;++j)
			{
				if(board[j][i]=='.')
					continue;
				if(arr[board[j][i]-'1']==1)
					return false;
				arr[board[j][i]-'1']=1;
			}
		}
		for(int i=0;i<9;i+=3)
			for(int j=0;j<9;j+=3)
			{
				memset(arr,0,sizeof(arr));
				for(int m=i;m<i+3;++m)
					for(int n=j;n<j+3;++n)
					{
						if(board[m][n]=='.')
					       continue;
				        if(arr[board[m][n]-'1']==1)
					      return false;
				        arr[board[m][n]-'1']=1;
					}
			}
		return true;
}

int main()
{
	
}