#include  <stdio.h>
#include  <stack>
using namespace std;

struct matrix
{
	int row;
	int column;
	matrix(int r=0,int c=0):row(r),column(c){}
};

matrix m[26];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		char str[2];
		int r,c;
		for(int i=0;i<n;++i)
		{
			scanf("%s%d%d",str,&r,&c);
			m[str[0]-'A']=matrix(r,c);
		}
		char expression[1000];
		while(scanf("%s",expression)!=EOF)
		{
			char* p=expression;
			int multi_counts=0;
			stack<matrix> matrix_stack;
			bool error=false;
			while(*p!='\0')
			{
				if(*p=='(')
					++p;
				else if(*p==')')
				{
					matrix a,b;
					b=matrix_stack.top();
					matrix_stack.pop();
					a=matrix_stack.top();
					matrix_stack.pop();
					if(a.column!=b.row)
					{
						error=true;
						break;
					}
					multi_counts+=a.row*a.column*b.column;
					matrix_stack.push(matrix(a.row,b.column));
					++p;
				}
				else
				{
					matrix_stack.push(m[*p-'A']);
					++p;
				}
			}
			if(error)
				printf("error\n");
			else
				printf("%d\n",multi_counts);
		}
		
	}
	return 0;
}