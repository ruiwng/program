#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;

int info[260][260];

int main()
{
	int n;
	info['A']['A']=5;
	info['A']['C']=-1;
	info['A']['G']=-2;
	info['A']['T']=-1;
	info['A']['-']=-3;

	info['C']['A']=-1;
	info['C']['C']=5;
	info['C']['G']=-3;
	info['C']['T']=-2;
	info['C']['-']=-4;

	info['G']['A']=-2;
	info['G']['C']=-3;
	info['G']['G']=5;
	info['G']['T']=-2;
	info['G']['-']=-2;

	info['T']['A']=-1;
	info['T']['C']=-2;
	info['T']['G']=-2;
	info['T']['T']=5;
	info['T']['-']=-1;

	info['-']['A']=-3;
	info['-']['C']=-4;
	info['-']['G']=-2;
	info['-']['T']=-1;
	info['-']['-']=0;

	int hash[110][110];
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			memset(hash,0,sizeof(hash));
			int length1,length2;
			char str1[110];
			char str2[110];
			scanf("%d%s",&length1,str1);
			scanf("%d%s",&length2,str2);
			for(int k=0;k<length1;++k)
			{
				hash[k+1][0]=hash[k][0]+info[str1[k]]['-'];
				hash[k+1][length2]=hash[k][length2]+info[str1[k]]['-'];
			}
			for(int k=0;k<length2;++k)
			{
				hash[0][k+1]=hash[0][k]+info['-'][str2[k]];
				hash[length1][k+1]=hash[length1][k]+info['-'][str2[k]];
			}
			for(int j=0;j<length1;++j)
			{
				for(int k=0;k<j;++k)
					hash[k+1][0]=hash[k][0]+info[str1[k]]['-'];
				for(int k=0;k<length2;++k)
				{
					hash[j+1][k+1]=max(max(hash[j][k]+info[str1[j]][str2[k]],hash[j+1][k]+info['-'][str2[k]]),
						hash[j][k+1]+info[str1[j]]['-']);
				}			
			}
			printf("%d\n",hash[length1][length2]);
		}
		
	}
	return 0;
}