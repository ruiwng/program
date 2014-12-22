#include  <stdio.h>
#include  <string.h>

char contents[32][9];

unsigned char accumulator=0;
unsigned char pc=0;
bool terminate;
void decimal_to_binary(int n,char* s)
{
	int index=7;
	while(n!=0)
	{
		s[index]=n%2+'0';
		n/=2;
		--index;
	}
}

int binary_to_decimal(char* s)
{
	int result=0;
	while(*s!='\0')
	{
		result<<=1;
		result+=*s-'0';
		++s;
	}
	return result;
}

char* instructions[8]=
{
	"000",
	"001",
	"010",
	"011",
	"100",
	"101",
	"110",
	"111"
};

void operations0(char* s)
{
	int t=binary_to_decimal(s+3);
	char temp[9];
	memset(temp,0,sizeof(temp));
	for(int i=0;i<8;++i)
		temp[i]='0';
	decimal_to_binary(accumulator,temp);
	strcpy(contents[t],temp);
}

void operations1(char* s)
{
	accumulator=binary_to_decimal(contents[binary_to_decimal(s+3)]);
}

void operations2(char* s)
{
	if(accumulator==0)
	    pc=binary_to_decimal(s+3);
}

void operations3(char* s)
{
	return;
}

void operations4(char* s)
{
	accumulator-=1;
}

void operations5(char* s)
{
	accumulator+=1;
}

void operations6(char* s)
{
	pc=binary_to_decimal(s+3);
}

void operations7(char* s)
{
	terminate=true;
}

typedef void (*operations)(char*);

operations opers_array[8]=
{
	operations0,operations1,operations2,operations3,
	operations4,operations5,operations6,operations7
};

int main()
{
	while(scanf("%s",contents[0])!=EOF)
	{
		for(int i=1;i<32;++i)
			scanf("%s",contents[i]);

		accumulator=0;
		pc=0;
		terminate=false;
		while(!terminate)
		{
			int temp=pc;
			if(++pc==32)
				pc=0;
			for(int i=0;i<8;++i)
			{
				if(strncmp(contents[temp],instructions[i],3)==0)
				{
					opers_array[i](contents[temp]);
					break;
				}
			}
		}
		char temp[9];
		memset(temp,0,sizeof(temp));
		for(int i=0;i<8;++i)
			temp[i]='0';
		decimal_to_binary(accumulator,temp);
		printf("%s\n",temp);
	}
	return 0;
}