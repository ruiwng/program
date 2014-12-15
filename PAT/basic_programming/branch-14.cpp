#include  <stdio.h>

int main()
{
	int num1,num2;
	char oper;
	while(scanf("%d %c %d",&num1,&oper,&num2)!=EOF)
	{
		switch(oper)
		{
		case '+':
			printf("%d\n",num1+num2);
			break;
		case '-':
			printf("%d\n",num1-num2);
			break;
		case '*':
			printf("%d\n",num1*num2);
			break;
		case '/':
			printf("%d\n",num1/num2);
			break;
		case '%':
			printf("%d\n",num1%num2);
			break;
		default:
			printf("ERROR\n");
		}
	}
	return 0;
}