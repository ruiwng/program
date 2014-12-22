#include  <stdio.h>
#include  <string.h>
#include  <vector>

using namespace std;

int traversed[1001][1001];

char* operation[6]=
{
	"fill A\n",//0
	"fill B\n",//1
	"empty A\n",//2
	"empty B\n",//3
	"pour A B\n",//4
	"pour B A\n",//5
};

enum OPER
{
	FILL_A=0,
	FILL_B,
	EMPTY_A,
	EMPTY_B,
	POUR_A_B,
	POUR_B_A
};

int Ca,Cb,N;
vector<OPER> result;

void print_result()
{
	int length=result.size();
	for(int i=0;i<length;++i)
		printf("%s",operation[result[i]-FILL_A]);
}

bool func(int a,int b)
{
	if(traversed[a][b])
		return false;
	traversed[a][b]=1;
	if(b==N)//condition satisfied
	{
		print_result();
		return true;
	}
	else if(a==0&&b==0)// both A and B empty
	{
		result.push_back(FILL_A);
		if(func(Ca,0))
			return true;
		result.pop_back();
		result.push_back(FILL_B);
		if(func(0,Cb))
			return true;
		result.pop_back();
	}
	else if(a==Ca&&b==0)// A full and B empty
	{
		result.push_back(POUR_A_B);
		if(func(0,Ca))
			return true;
		result.pop_back();
	}
	else if(a==0&&b==Cb)// A empty and B full
	{
		result.push_back(POUR_B_A);
		if(func(Ca,Cb-Ca))
			return true;
		result.pop_back();
	}
	else if(a==0&&b>0&&b<Cb)//A empty and B neither full nor empty
	{
		result.push_back(FILL_A);
		if(func(Ca,b))
			return true;
		result.pop_back();
		result.push_back(POUR_B_A);
		if(b>=Ca)
		{
			if(func(Ca,b-Ca))
				return true;
		}
		else
		{
			if(func(b,0))
				return true;
		}
		result.pop_back();
	}
	else if(a>0&&a<Cb&&b==0)//A neither full nor empty and B empty
	{
		result.push_back(POUR_A_B);
		if(func(0,a))
			return true;
		result.pop_back();
		result.push_back(FILL_B);
		if(func(a,Cb))
			return true;
		result.pop_back();
	}
	else if(a==Ca&&&b>0&&b<Cb)//A full and B neither empty nor full
	{
		result.push_back(POUR_A_B);
		if(Ca+b<=Cb)
		{
			if(func(0,Ca+b))
				return true;
		}
		else
		{
			if(func(Ca+b-Cb,Cb))
				return true;
		}
		result.pop_back();
		result.push_back(EMPTY_A);
		if(func(0,b))
			return true;
		result.pop_back();
	}
	else if(a>0&&a<Ca&&b==Cb)//A neither empty nor full and B full
	{
		result.push_back(POUR_B_A);
		if(func(Ca,Cb+a-Ca))
			return true;
		result.pop_back();
		result.push_back(EMPTY_B);
		if(func(a,0))
			return true;
		result.pop_back();
	}
	return false;
}
int main()
{
	while(scanf("%d%d%d",&Ca,&Cb,&N)!=EOF)
	{
		result.clear();
		memset(traversed,0,sizeof(traversed));
		func(0,0);
		printf("success\n");
	}
	return 0;
}