#include  <stdio.h>
#include  <string.h>
#include  <stack>
#include  <string>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		
		for(int i=0;i<n;++i)
		{
			getchar();
			if(i>0)
				printf("\n");
			string current_page("http://www.acm.org/");
			stack<string> back_stack;
			stack<string> forward_stack;
			char str[10];
			while(scanf("%s",str)!=EOF)
			{
				if(strcmp(str,"QUIT")==0)
					break;

				if(strcmp(str,"VISIT")==0)
				{
					char URL[75];
					scanf("%s",URL);
					back_stack.push(current_page);
					printf("%s\n",URL);
					current_page=URL;
					while(!forward_stack.empty())
						forward_stack.pop();
				}
				else if(strcmp(str,"BACK")==0)
				{
					if(!back_stack.empty())
					{
						forward_stack.push(current_page);
						current_page=back_stack.top();
						back_stack.pop();
						printf("%s\n",current_page.c_str());
					}
					else
						printf("Ignored\n");
				}
				else if(strcmp(str,"FORWARD")==0)
				{
					if(!forward_stack.empty())
					{
						back_stack.push(current_page);
						current_page=forward_stack.top();
						forward_stack.pop();
						printf("%s\n",current_page.c_str());
					}
					else
						printf("Ignored\n");
				}
			}
		}
	}
	return 0;
}