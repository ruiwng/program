#include  <stdio.h>

int main()
{	
	int num1,num2;
	char oper;
	scanf("%d",&num1);
	int error=0;
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
		    	error=1;
			else
				num1/=num2;
			break;
		default:
			error=1;
			break;
		}
		if(error==1)
			break;
	}
	if(error==1)
		printf("ERROR\n");
	else
	    printf("%d\n",num1);
	return 0;
}