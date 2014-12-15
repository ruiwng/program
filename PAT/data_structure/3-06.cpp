/*#include  <stdio.h>
#include  <string.h>
#include  <stack>
using namespace std;

int priority_array[512][512];
int main()
{
	priority_array['*']['-']=1;
	priority_array['-']['*']=-1;
	priority_array['/']['-']=1;
	priority_array['-']['/']=-1;
	priority_array['*']['+']=1;
	priority_array['+']['*']=-1;
	priority_array['/']['+']=1;
	priority_array['+']['/']=-1;
	priority_array['+'][')']=1;
	priority_array['-'][')']=1;
	priority_array['*'][')']=1;
	priority_array['/'][')']=1;
	priority_array['('][')']=1;
	priority_array['(']['+']=-1;
	priority_array['(']['-']=-1;
	priority_array['(']['*']=-1;
	priority_array['(']['/']=-1;
	priority_array['+']['/n']=1;
	priority_array['-']['/n']=1;
	priority_array['*']['/n']=1;
	priority_array['/']['/n']=1;

	double number=0.0;
	stack<double> number_stack;
	stack<char> operator_stack;
	bool first=true;
	bool numeric=false;
	char str[25];
	fgets(str,25,stdin);
	int length=strlen(str);
	char* p=str;
	while(*p!='\0')
	{
		while(*p=='(')
		{
			operator_stack.push('(');
			++p;
		}
		sscanf(p,"%lf",&number);
		char str_temp[30];
		sprintf(str_temp,"%g",number);
		if(*p=='+')
			++p;
		p+=strlen(str_temp);
		number_stack.push(number);
		if(first)
			first=false;
		else
			printf(" ");
		printf("%g",number);
		while(*p=='+'||*p=='-'||*p=='*'||*p=='/'||*p==')'||*p=='\n')
		{
			 if(!operator_stack.empty())
			  while(!operator_stack.empty()&&priority_array[operator_stack.top()][*p]>=0)
			  {
				if(operator_stack.top()=='(')
				{
					operator_stack.pop();
					break;
				}
				printf(" %c",operator_stack.top());
				double temp_number1=number_stack.top();
				number_stack.pop();
				double temp_number2=number_stack.top();
				number_stack.pop();
				double result;
				switch(operator_stack.top())
				{
					case '+':
						result=temp_number1+temp_number2;
						break;
					case '-':
						result=temp_number2-temp_number1;
						break;
					case '*':
						result=temp_number1*temp_number2;
						break;
					case '/':
						result=temp_number2/temp_number1;
						break;
			    }
				number_stack.push(result);
				operator_stack.pop();
			  }
			if(*p!=')')
				  operator_stack.push(*p);
			++p;
			if(*(p-1)!=')')
				break;
		}
	}	
	printf("\n");
	return 0;
}*/

#include  <stdio.h>
#include  <string.h>
#include  <stack>
using namespace std;

int priority_array[512];
int main()
{
	priority_array['+']=1;
    priority_array['-']=1;
    priority_array['*']=2;
    priority_array['/']=2;

	stack<char> operator_stack;
	bool first=true;
	bool numeric=false;
	char str[25];
	fgets(str,25,stdin);
	int length=strlen(str);
	char* p=str;
	while(*p!='\0')
	{
		while(*p=='(')
		{
			operator_stack.push('(');
			++p;
		}
		if(*p=='+')
			++p;
		if(first)
			first=false;
		else
			printf(" ");
		do
		{
			printf("%c",*p);
			++p;
		}while(*p!='+'&&*p!='-'&&*p!='*'&&*p!='/'&&*p!=')'&&*p!='\n');
		while(*p=='+'||*p=='-'||*p=='*'||*p=='/'||*p==')'||*p=='\n')
		{
			 if(!operator_stack.empty())
			  while(!operator_stack.empty()&&priority_array[operator_stack.top()]>=priority_array[*p])
			  {
				if(operator_stack.top()=='(')
				{
					operator_stack.pop();
					break;
				}
				printf(" %c",operator_stack.top());
				operator_stack.pop();
			  }
			if(*p!=')')
				  operator_stack.push(*p);
			++p;
			if(*(p-1)!=')')
				break;
		}
	}	
	printf("\n");
	return 0;
}