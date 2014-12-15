#include  <string.h>
#include  <stdio.h>
#include  <stack>
#include  <vector>
using namespace std;
int main()
{
    char str[40];
	fgets(str,40,stdin);
	int length=strlen(str);
	if(str[length-1]=='\n')
		str[length-1]='\0';

	char *pos1=str;
	char *pos2=str;
	stack<double> number_stack;
	stack<char> operator_stack;
	vector<int> oper;
	bool error=false;
	while(pos1!=NULL&&*pos1!='\0')
	{
		pos2=strchr(pos1,' ');
		if((*pos1=='+'||*pos1=='-'||*pos1=='*'||*pos1=='/')&&pos2-pos1==1)
		{
		  operator_stack.push(*pos1);
		  oper.push_back(1);
		}
		else
		{
			double current_number;
			sscanf(pos1,"%lf",&current_number);
			while(!oper.empty()&&oper.back()==0)
			{
				oper.pop_back();
				double temp=number_stack.top();
				number_stack.pop();
				oper.pop_back();
				switch(operator_stack.top())
				{
				case '+':
					current_number=temp+current_number;
					break;
				case '-':
					current_number=temp-current_number;
					break;
				case '*':
					current_number=temp*current_number;
					break;
				case '/':
					if(current_number==0.0)
					{
						error=true;
						break;
					}
					current_number=temp/current_number;
					break;
				}
				operator_stack.pop();
				if(error)
					break;
			}
			number_stack.push(current_number);
			oper.push_back(0);
		}
		if(error)
			break;
		while(pos2!=NULL&&*pos2==' ')
		 ++pos2;
		pos1=pos2;
	}
	if(!error)
		printf("%.1lf\n",number_stack.top());
	else
		printf("ERROR\n");
	return 0;
}