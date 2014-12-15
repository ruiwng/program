#include <stdio.h>
#include <math.h>
#include <string.h>
#include  <string>
#include  <vector>
using namespace std;
int array[100000];
int main()
{
	int num;
	int radix;
	int x=pow(100000,0.5);
	array[1]=1;
	for(int i=2;i<x;i++)
	{
		if(!array[i])
		{
			int temp=100000/i;
			for(int j=2;j<=temp;j++)
				array[j*i]=1;
		}
	}
	vector<int> intVec;
	while(!intVec.empty())
		intVec.pop_back();
	while(scanf("%d",&num)!=EOF)
	{
		if(num<0)
			break;
		scanf("%d",&radix);
		if(array[num])
		{
			intVec.push_back(0);
			continue;
		}
		string str;
	    while(num)
		{
			str.push_back(num%radix+'0');
			num/=radix;
		}
		int num2=0;
		for(string::iterator iter=str.begin();iter!=str.end();iter++)
		{
			 num2=num2*radix+*iter-'0';
		}
		if(array[num2])
		   intVec.push_back(0);
		else
			intVec.push_back(1);
	}
	for(vector<int>::const_iterator iter=intVec.begin();iter!=intVec.end();iter++)
	{
		if(*iter)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}