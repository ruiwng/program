#include  <stdio.h>
#include  <string.h>
#include  <vector>
using namespace std;

vector<vector<int> > result;
vector<int> factors;

void f(vector<int> current_result,int index,int current_value)
{
	if(current_value==1)
	{
		result.push_back(current_result);
		return;
	}
	if(factors.size()<=index||index>current_value)
		return;
	f(current_result,index+1,current_value);
	if(current_value%factors[index]==0)
	{
		current_result.push_back(factors[index]);
		f(current_result,index+1,current_value/factors[index]);
	}
}

void func(int n)
{
	factors.clear();
	for(int i=2;i<101;++i)
		if(n%i==0)
			factors.push_back(i);
	f(vector<int>(),0,n);
}

int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		result.clear();
		if(a<b)
		{
			int temp=a;
			a=b;
			b=temp;
		}
		func(b);
		if(result.empty())
			printf("%d\n",a);
		else
		{
		    vector<vector<int> > result_a=result;
			result.clear();
			func(a);
			int length1=result_a.size();
			int length2=result.size();
			bool success=false;
			for(int i=0;i<length1;++i)
			{
				int hash[101];
				memset(hash,0,sizeof(hash));
				vector<int>& temp(result_a[i]);
				for(int m=0;m<temp.size();++m)
					hash[temp[m]]=1;
				for(int j=0;j<length2;++j)
				{
					vector<int>& t(result[j]);
					int m=0;
					for(;m<t.size();++m)
					{
						if(hash[t[m]]==1)
							break;
					}
					if(m==t.size())
					{
						success=true;
						break;
					}
				}
				if(success)
					break;
			}
			if(success)
				printf("%d\n",a);
			else
				printf("%d\n",b);
		}
	}
	return 0;
}