#include  <stdio.h>
#include  <string>
#include  <stack>
#include  <vector>
#include  <deque>
using namespace std;

char* str_temp[4]=
{
	"+",
	"-",
	"*",
	"/"
};

bool compute(deque<string> temp_array)
{
	stack<string> operand_array;
	while(!temp_array.empty())
	{
		if(temp_array.front()=="+"||temp_array.front()=="-"||
			temp_array.front()=="*"||temp_array.front()=="/")
		{
			string temp2=operand_array.top();
			operand_array.pop();
			string temp1=operand_array.top();
			operand_array.pop();
			int num1,num2;
			sscanf(temp2.c_str(),"%d",&num2);
			sscanf(temp1.c_str(),"%d",&num1);
			char result[10];
			if(temp_array.front()=="+")
                sprintf(result,"%d",num1+num2);
			else if(temp_array.front()=="-")
				sprintf(result,"%d",num1-num2);
			else if(temp_array.front()=="*")
				sprintf(result,"%d",num1*num2);
			else if(temp_array.front()=="/")
			{
				if(num2==0||num1%num2!=0)
					return false;
				sprintf(result,"%d",num1/num2);
			}
			operand_array.push(result);
		}
		else
			operand_array.push(temp_array.front());
		temp_array.pop_front();
	}
	if(operand_array.top()=="24")
		return true;
	else
		return false;
}

void print_result(deque<string>& temp_array)
{
	stack<string> operand_array;
	while(!temp_array.empty())
	{
		if(temp_array.front()=="+"||temp_array.front()=="-"||
			temp_array.front()=="*"||temp_array.front()=="/")
		{
			string temp2=operand_array.top();
			operand_array.pop();
			string temp1=operand_array.top();
			operand_array.pop();
			string result;
			if(temp2.length()>2)
				temp2="("+temp2+")";
			if(temp1.length()>2)
				temp1="("+temp1+")";
			result=temp1+temp_array.front()+temp2;		
			operand_array.push(result);
		}
		else
			operand_array.push(temp_array.front());
		temp_array.pop_front();
	}
	printf("%s\n",operand_array.top().c_str());
}
bool exist(const vector<string>& operand_array,const vector<string>& operator_array)
{
	deque<string> temp_array(operand_array.begin(),operand_array.begin()+2);
	temp_array.push_back(*operator_array.begin());
	temp_array.push_back(*(operand_array.begin()+2));
	temp_array.push_back(*(operator_array.begin()+1));
	temp_array.push_back(*(operand_array.begin()+3));
	temp_array.push_back(*(operator_array.begin()+2));
	if(compute(temp_array))
	{
		print_result(temp_array);
		return true;
	}
	temp_array.assign(operand_array.begin(),operand_array.begin()+2);
	temp_array.push_back(*operator_array.begin());
	temp_array.push_back(*(operand_array.begin()+2));
	temp_array.push_back(*(operand_array.begin()+3));
	temp_array.push_back(*(operator_array.begin()+1));
	temp_array.push_back(*(operator_array.begin()+2));
	if(compute(temp_array))
	{
		print_result(temp_array);
		return true;
	}

	temp_array.assign(operand_array.begin(),operand_array.begin()+3);
	temp_array.push_back(*operator_array.begin());
	temp_array.push_back(*(operand_array.begin()+3));
	temp_array.push_back(*(operator_array.begin()+1));
	temp_array.push_back(*(operator_array.begin()+2));
	if(compute(temp_array))
	{
		print_result(temp_array);
		return true;
	}

	temp_array.assign(operand_array.begin(),operand_array.begin()+4);
	temp_array.push_back(*operator_array.begin());
	temp_array.push_back(*(operator_array.begin()+1));
	temp_array.push_back(*(operator_array.begin()+2));
	if(compute(temp_array))
	{
		print_result(temp_array);
		return true;
	}
	return false;
}
int main()
{
	char str[4][4];
	while(scanf("%s %s %s %s",str[0],str[1],str[2],str[3])!=EOF)
	{
		vector<string> operand_array(4);
		vector<string> operator_array(3);
		bool exist_temp=false;
		for(unsigned int i=0;i<4;++i)
		{
			operand_array[0]=str[i];
			for(unsigned int j=0;j<4;++j)
			{
				if(j==i)
					continue;
				operand_array[1]=str[j];
				for(unsigned int k=0;k<4;++k)
				{
					if(k==j||k==i)
						continue;
					operand_array[2]=str[k];
					for(unsigned int m=0;m<4;++m)
					{
						if(m==k||m==j||m==i)
							continue;
						operand_array[3]=str[m];
						for(unsigned int x=0;x<4;++x)
		                {
			                 operator_array[0]=str_temp[x];
			                 for(unsigned int y=0;y<4;++y)
			                 {
				                  operator_array[1]=str_temp[y];
				                  for(unsigned int z=0;z<4;++z)
								  {
					                 operator_array[2]=str_temp[z];
									 if(exist(operand_array,operator_array))
							             exist_temp=true;
									 if(exist_temp)
										 break;
								  }
								  if(exist_temp)
									  break;
			                 }				
							 if(exist_temp)
								 break;
		                }
						if(exist_temp)
							break;
					}
					if(exist_temp)
						break;
				}
				if(exist_temp)
					break;
			}
			if(exist_temp)
				break;
		}
		if(!exist_temp)
			printf("-1\n");
	}
	return 0;
}