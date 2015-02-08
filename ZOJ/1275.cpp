#include  <stdio.h>
#include  <string.h>

bool is_runaround(int n)
{
	char str[10];
	int tag[10];//tag digits appeared in the number, meanwhile, tag whether the corresponding position has already been traversed. 
	sprintf(str,"%d",n);
	memset(tag,0,sizeof(tag));
	int len=strlen(str);
	for(int i=0;i<len;++i)
		if(++tag[str[i]-'0']==2)
			return false;
	memset(tag,0,sizeof(tag));
	int index=0;//position current being traversed.
	int number=0;//number of position traversed.
	while(true)
	{
		++number;
		index+=str[index]-'0';
		index%=len;
		//exit the loop if back to the initial position or current position has already been traversed.
		if(index==0)
			break;
		if(tag[index]==1)
			return false;
		tag[index]=1;
	}
	return number==len;
}

int main()
{
	int n;
	int case_number=0;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		while(!is_runaround(n))
			++n;
		printf("Case %d: %d\n",++case_number,n);
	}
	return 0;
}