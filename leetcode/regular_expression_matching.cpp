#include  <string.h>
#include  <stdlib.h>

bool isMatch(char *s,char *p) {
    int column=strlen(s);
    int row=strlen(p);
    char *record=(char*)malloc((row+1)*(column+1)*sizeof(char));
    if(record==NULL)
       return false;
    memset(record,0,(row+1)*(column+1)*sizeof(char));
    record[0]=1;
    int start=0;
    for(int i=1;i<=row;)
    {
        char *prev=&record[(i-1)*(column+1)];
        char *curr=&record[i*(column+1)];
		char *next=&record[(i+1)*(column+1)];
        bool exist=false;
        int j=start;
		if(p[i-1]=='.')
        {
			if(p[i]!='*')
			{
				for(;j<column;++j)
				{
					if(prev[j]==1)
					{
						if(!exist)
						{
							start=j+1;
							exist=true;
						}
						curr[j+1]=1;
					}
				}
				++i;
			}
			else
			{
				exist=true;
                while(j<=column)
                   next[j++]=1;
				i+=2;
			}
        }
        else
        {
			if(p[i]!='*')
			{
				for(;j<column;++j)
				{
					if(prev[j]==1&&s[j]==p[i-1])
					{
						curr[j+1]=1;
						if(!exist)
						{
							start=j+1;
							exist=true;
						}
					}
				}
				++i;
			}
			else
			{
				exist=true;
				for(;j<=column;)
				{
					if(prev[j]==1)
					{
						while(true)
						{
							next[j++]=1;
							if(j>column||s[j-1]!=p[i-1])
								break;
						}
					}
					else
						++j;
				}
				i+=2;
			}
        }
        if(!exist)
            return false;
    }
    bool result=(record[(row+1)*(column+1)-1]==1);
    free(record);
    return result;
}

 int main()
 {
	 bool result=isMatch("aa","a");
	 result=isMatch("aa","aa");
	 result=isMatch("aaa","aa");
	 result=isMatch("aa","a*");
	 result=isMatch("aa",".*");
	 result=isMatch("ab",".*");
	 result=isMatch("aab","c*a*b");
	 return 0;
 }
