class Solution
{
public:
	vector<vector<string> > solveNQueens(int n)
	{
		place_array=new int[n+1];
		memset(place_array,0,sizeof(int)*(n+1));
		queen_number=n;
		n_queen();
		return result;
	}
private:
	void n_queen()
	{
		int k=1;
		while(k>0)
		{
			++place_array[k];
			while(place_array[k]<=queen_number&&!place(k))
				++place_array[k];
			if(k==queen_number&&place_array[k]<=queen_number)
			{
				vector<string> temp;
				for(int i=1;i<=queen_number;++i)
				{
					string temp_str(queen_number,'.');
					temp_str[place_array[i]-1]='Q';
					temp.push_back(temp_str);
				}
				result.push_back(temp);
			}
			else if(k<queen_number&&place_array[k]<=queen_number)
				++k;
			else
			{
				place_array[k]=0;
				--k;
			}
		}
	}
private:
	bool place(int n)
	{
		for(int i=1;i<n;++i)
		   if(place_array[i]==place_array[n]||abs(n-i)==abs(place_array[i]-place_array[n]))
			   return false;
		return true;
	}
private:
	int* place_array;
	int queen_number;
	vector<vector<string> > result;
};