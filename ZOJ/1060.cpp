#include  <stdio.h>
#include  <string.h>

int info[26][26];

int main()
{
	int n,m;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==0&&n==0)
			break;
        int cmp_num=m*(m-1)/2;
		memset(info,0,sizeof(info));
		char result[200];
		bool over=false;
		for(int i=0;i<n;++i)
		{
			char str[10];
			scanf("%s",str);
			if(over)
				continue;
			if(str[0]-'A'==str[2]-'A'||info[str[0]-'A'][str[2]-'A']==1)
			{
				over=true;
				sprintf(result,"Inconsistency found after %d relations.\n",i+1);
				continue;
			}
            if(info[str[0]-'A'][str[2]-'A']!=0)
                continue;
			info[str[0]-'A'][str[2]-'A']=-1;
			info[str[2]-'A'][str[0]-'A']=1;
            --cmp_num;
			for(int j=0;j<m;++j)
			{
				if(j==str[0]-'A')
					continue;
				else if(info[str[0]-'A'][j]==1&&info[j][str[2]-'A']==0)
				{
                    --cmp_num;
					info[j][str[2]-'A']=-1;
					info[str[2]-'A'][j]=1;
				}
			}
			for(int j=0;j<m;++j)
			{
				if(j==str[2]-'A')
					continue;
				else if(info[str[2]-'A'][j]==-1&&info[str[0]-'A'][j]==0)
				{
                    --cmp_num;
					info[str[0]-'A'][j]=-1;
					info[j][str[0]-'A']=1;
				}
			}
			if(cmp_num==0)
			{
				char temp[30];
				memset(temp,0,sizeof(temp));
				for(int j=0;j<m;++j)
				{
					int rank=0;
					for(int k=0;k<m;++k)
					{
						if(info[j][k]==1)
							++rank;
					}
					temp[rank]='A'+j;
				}
				over=true;
				sprintf(result,"Sorted sequence determined after %d relations: %s.\n",i+1,temp);
			}
		}
		if(!over)
		   printf("Sorted sequence cannot be determined.\n");
		else
			printf("%s",result);
	}
	return 0;
}
