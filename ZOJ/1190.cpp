#include  <stdio.h>
#include  <vector>
#include  <stack>
#include  <algorithm>
using namespace std;

enum OPER
{
	ADD=0,
	DIV,
	DUP,
	MUL,
	SUB,
	NUM
};

char *operations[5]=
{
	"ADD",
	"DIV",
	"DUP",
	"MUL",
	"SUB"
};

vector<OPER> oper_array;
vector<int> source_array;
vector<int> dest_array;
int n;

void print_result()
{
	int len=oper_array.size();
	for(int i=0;i<len;++i)
	  printf("%s%c",operations[oper_array[i]-ADD],i==len-1?'\n':' ');
}
int index;
bool oper_exe()
{
	int len=oper_array.size();
	for(int i=0;i<n;++i)
	{
		stack<int> num_stack;
		num_stack.push(source_array[i]);
		for(int j=0;j<len;++j)
		{
            if(num_stack.empty())
			{
				index=j;
				return false;
			}
		    if(oper_array[j]==DUP)
				num_stack.push(num_stack.top());
			else
			{
				if(num_stack.size()<2)
				{
					index=j;
					return false;
				}
				int b=num_stack.top();
				num_stack.pop();
				int a=num_stack.top();
				num_stack.pop();
				switch(oper_array[j])
				{
				case ADD:
					num_stack.push(a+b);
					break;
				case SUB:
					num_stack.push(a-b);
					break;
				case MUL:
					num_stack.push(a*b);
					break;
				case DIV:
					if(b==0)
					{
						index=j;
						return false;
					}
					num_stack.push(a/b);
					break;
				}
				if(abs(num_stack.top()>30000))
				{
					index=j;
			        return false;
				}
			}
		}
		if(!(num_stack.size()==1&&num_stack.top()==dest_array[i]))
			return false;
	}
	return true;
}

int main()
{
	int program_number=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		source_array.clear();
		dest_array.clear();
		source_array.reserve(n);
		dest_array.reserve(n);
		for(int i=0;i<n;++i)
		{
			int t;
			scanf("%d",&t);
			source_array.push_back(t);
		}
		for(int i=0;i<n;++i)
		{
			int t;
			scanf("%d",&t);
			dest_array.push_back(t);
		}
		bool empty=true;
		for(int i=0;i<n;++i)
		{
			if(source_array[i]!=dest_array[i])
			{
				empty=false;
				break;
			}
		}
		printf("Program %d\n",++program_number);
		if(empty)
			printf("Empty sequence\n");
		else
		{
			bool success=false;
			for(int i=1;!success&&i<11;++i)
			{
				oper_array.assign(i,ADD);
				index=-1;
				while(!success)
				{
					if(oper_exe())
					{
						success=true;
						break;
					}
					int k=i-1;
					if(index!=-1)
					{
						k=index;
						for(int j=index+1;j<i;++j)
							oper_array[j]=ADD;
						index=-1;
					}
					while(k>=0)
					{
						oper_array[k]=static_cast<OPER>(static_cast<int>(oper_array[k])+1);
						if(oper_array[k]==NUM)
						{
							oper_array[k]=ADD;
							--k;
						}
						else
							break;
					}
					if(k<0)
						break;
				}
			}
			if(success)
				print_result();
			else
				printf("Impossible\n");
		}
		printf("\n");
	}
	return 0;
}