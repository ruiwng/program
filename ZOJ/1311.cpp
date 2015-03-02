#include  <stdio.h>
#include  <string.h>

int state_info[101][101];
int dep[101];
int low[101];
int cut[101];
int num_places;
int root;
int son;

void dfs(int index,int depth)
{
	dep[index]=low[index]=depth;
	for(int i=1;i<=num_places;++i)
	{
		if(state_info[index][i]!=0)
		{
			if(dep[i]==0)
			{
				dfs(i,depth+1);
				if(index==root)
					++son;
				else
				{
					low[index]=low[index]<low[i]?low[index]:low[i];
					if(low[i]>=dep[index])
						cut[index]=1;
				}
				
			}
			else
				low[index]=low[index]<dep[i]?low[index]:dep[i];
		}
	}
}

int main()
{	
	while(scanf("%d\n",&num_places)!=EOF&&num_places)
	{
		memset(state_info,0,sizeof(state_info));
		memset(dep,0,sizeof(dep));
		memset(low,0,sizeof(low));
		memset(cut,0,sizeof(cut));
		char str[100];
		int n1,n2;
		while(scanf("%d",&n1))
		{
			if(n1==0)
				break;
			fgets(str,100,stdin);
			char *p=str;
			while(*p==' ')
				++p;
			while(sscanf(p,"%d",&n2)==1)
			{
				state_info[n1][n2]=1;
				state_info[n2][n1]=1;
				p=strchr(p,' ');
				if(p==NULL)
					break;
				while(*p==' ')
					++p;
			}
		}
		root=1;
		son=0;
		dfs(root,1);
		if(son>1)
			cut[root]=1;
		int cut_count=0;
		for(int i=1;i<=num_places;++i)
			cut_count+=cut[i];
		printf("%d\n",cut_count);
	}
	return 0;
}