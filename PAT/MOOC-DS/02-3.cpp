#include  <stdio.h>
#include  <string.h>
#include  <string>
#include  <stack>
using namespace std;

bool is_opera(string s)
{
	if(s.size()==1&&(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'))
		return true;
	return false;
}

int main()
{
	char str[40];
	while(fgets(str,40,stdin)!=NULL)
	{
		char *p=str;
		char temp[10];
		stack<string> expression;
		int error=0;
		while(sscanf(p,"%s",&temp)==1)
		{
			if(!error)
			{
				if(!is_opera(temp))
				{
					while(!expression.empty()&&!is_opera(expression.top()))
					{
						double x,y;
						char t[20];
						strcpy(t,expression.top().c_str());
						sscanf(t,"%lf",&x);
						sscanf(temp,"%lf",&y);
						expression.pop();
						if(!expression.empty()&&is_opera(expression.top()))
						{
							switch(expression.top()[0])
							{
							case '+':
								y=x+y;
								break;
							case '-':
								y=x-y;
								break;
							case '*':
								y=x*y;
								break;
							case '/':
								if(y!=0.0)
									y=x/y;
								else
									error=1;
								break;
							}
						}
						else
						{
							error=1;
							break;
						}
						if(error)
							break;
						sprintf(temp,"%lf",y);
						expression.pop();
					}
				}
				expression.push(temp);
			}
			while(*p==' ')
				++p;
			p=strchr(p,' ');
			if(p==NULL)
				break;
		}
		if(error)
			printf("ERROR\n");
		else
		{
			char temp[20];
			strcpy(temp,expression.top().c_str());
			double result;
			sscanf(temp,"%lf",&result);
			printf("%.1lf\n",result);
		}
	}
	return 0;
}