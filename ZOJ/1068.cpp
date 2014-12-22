#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;

char morse_code[260][5];

char code1[2];
char code2[2][2];
char code3[2][2][2];
char code4[2][2][2][2];

int main()
{
	strcpy(morse_code['A'],"01");
	strcpy(morse_code['B'],"1000");
	strcpy(morse_code['C'],"1010");
	strcpy(morse_code['D'],"100");
	strcpy(morse_code['E'],"0");
	strcpy(morse_code['F'],"0010");
	strcpy(morse_code['G'],"110");
	strcpy(morse_code['H'],"0000");
	strcpy(morse_code['I'],"00");
	strcpy(morse_code['J'],"0111");
	strcpy(morse_code['K'],"101");
	strcpy(morse_code['L'],"0100");
	strcpy(morse_code['M'],"11");
	strcpy(morse_code['N'],"10");
	strcpy(morse_code['O'],"111");
	strcpy(morse_code['P'],"0110");
	strcpy(morse_code['Q'],"1101");
	strcpy(morse_code['R'],"010");
	strcpy(morse_code['S'],"000");
	strcpy(morse_code['T'],"1");
	strcpy(morse_code['U'],"001");
	strcpy(morse_code['V'],"0001");
	strcpy(morse_code['W'],"011");
	strcpy(morse_code['X'],"1001");
	strcpy(morse_code['Y'],"1011");
	strcpy(morse_code['Z'],"1100");
	strcpy(morse_code['_'],"0011");
	strcpy(morse_code['.'],"1110");
	strcpy(morse_code[','],"0101");
	strcpy(morse_code['?'],"1111");
	code1[0]='E';
	code1[1]='T';
	code2[0][0]='I';
	code2[0][1]='A';
	code2[1][0]='N';
	code2[1][1]='M';
	code3[0][0][0]='S';
	code3[0][0][1]='U';
	code3[0][1][0]='R';
	code3[0][1][1]='W';
	code3[1][0][0]='D';
	code3[1][0][1]='K';
	code3[1][1][0]='G';
	code3[1][1][1]='O';
	code4[0][0][0][0]='H';
	code4[0][0][0][1]='V';
	code4[0][0][1][0]='F';
	code4[0][0][1][1]='_';
	code4[0][1][0][0]='L';
	code4[0][1][0][1]=',';
	code4[0][1][1][0]='P';
	code4[0][1][1][1]='J';
	code4[1][0][0][0]='B';
	code4[1][0][0][1]='X';
	code4[1][0][1][0]='C';
	code4[1][0][1][1]='Y';
	code4[1][1][0][0]='Z';
	code4[1][1][0][1]='Q';
	code4[1][1][1][0]='.';
	code4[1][1][1][1]='?';

	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			char str[110];
			scanf("%s",str);
			char* p=str;
			int length=0;
			char info[500];
			char* q=info;
			memset(info,0,sizeof(info));
			int length_info[110];
			memset(length_info,0,sizeof(length_info));
			while(*p!='\0')
			{
				strcpy(q,morse_code[*p]);
				length_info[length]=strlen(morse_code[*p]);
				q+=length_info[length++];
				++p;
			}
			printf("%d: ",i+1);
			q=info;
			reverse(length_info,length_info+length);
			for(int j=0;j<length;++j)
			{
				if(length_info[j]==1)
				{
					printf("%c",code1[*q-'0']);
					++q;
				}
				else if(length_info[j]==2)
				{
					printf("%c",code2[*q-'0'][*(q+1)-'0']);
					q+=2;
				}
				else if(length_info[j]==3)
				{
					printf("%c",code3[*q-'0'][*(q+1)-'0'][*(q+2)-'0']);
					q+=3;
				}
				else if(length_info[j]==4)
				{
					printf("%c",code4[*q-'0'][*(q+1)-'0'][*(q+2)-'0'][*(q+3)-'0']);
					q+=4;
				}
			}
			printf("\n");
		}
	}
	return 0;
}