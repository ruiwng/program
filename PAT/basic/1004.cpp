#include  <stdio.h>

struct student
{
	char name[11];
	char number[11];
	int score;
};
int main()
{
	int n;
	student stu;
	student high,low;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
		    scanf("%s %s %d",stu.name,stu.number,&stu.score);
			if(i==0)
			{
				high=low=stu;
				continue;
			}
			if(stu.score>high.score)
				high=stu;
			if(stu.score<low.score)
				low=stu;
		}
		printf("%s %s\n",high.name,high.number);
		printf("%s %s\n",low.name,low.number);
	}
    return 0;
}
