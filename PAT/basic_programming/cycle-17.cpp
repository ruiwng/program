/*优先级不同的方法*/
/*#include  <stdio.h>
#include  <stack>
using namespace std;

char array[256][256];
int main()
{
	array['+']['-']=1;
	array['-']['+']=1;
	array['+']['*']=0;
	array['*']['+']=2;	
	array['+']['/']=0;
	array['/']['+']=2;
	array['-']['*']=0;
	array['*']['-']=2;
	array['-']['/']=0;
	array['/']['-']=2;
	array['*']['/']=1;
	array['/']['*']=1;

	array['+']['=']=1;
	array['-']['=']=1;
	array['*']['=']=1;
	array['/']['=']=1;
	stack<int> num_stack;
	stack<int> operator_stack;
	while(true)
	{
		int temp;
		char oper1;
		scanf("%d",&temp);
		num_stack.push(temp);
		scanf("%c",&oper1);
		if(operator_stack.empty())
			operator_stack.push(oper1);
		else
		{
			char oper2=operator_stack.top();
			while(array[oper2][oper1]>=1)
			{
				int num1=num_stack.top();
				num_stack.pop();
				int num2=num_stack.top();
				num_stack.pop();
				int result;
				switch(oper2)
				{
				case '+':
					result=num1+num2;
					break;
				case '-':
					result=num2-num1;
					break;
				case '*':
					result=num1*num2;
					break;
				case '/':
					result=num2/num1;
					break;
				}
				num_stack.push(result);
				operator_stack.pop();
				if(!operator_stack.empty())
				    oper2=operator_stack.top();
				else
					break;
			}
			if(oper1=='=')
				break;
			else
			    operator_stack.push(oper1);
		}
	}
	printf("%d\n",num_stack.top());
	return 0;
}
*/

#include  <stdio.h>

int main()
{	
	int num1,num2;
	char oper;
	scanf("%d",&num1);
	bool error=false;
	while(scanf("%c",&oper))
	{
		if(oper=='=')
			break;
		scanf("%d",&num2);
		switch(oper)
		{
		case '+':
			num1+=num2;
			break;
		case '-':
			num1-=num2;
			break;
		case '*':
			num1*=num2;
			break;
		case '/':
			if(num2==0)
		    	error=true;
			else
				num1/=num2;
			break;
		default:
			error=true;
			break;
		}
		if(error)
			break;
	}
	if(error)
		printf("ERROR\n");
	else
	    printf("%d\n",num1);
	return 0;
}