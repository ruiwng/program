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
    for(int i=1;i<=row;++i)
    {
        char *prev=&record[(i-1)*(column+1)];
        char *curr=&record[i*(column+1)];
        bool exist=false;
        int j=start;
        if(p[i-1]=='*')
        {
            exist=true;
            while(j<=column)
                curr[j++]=1;
        }
        else if(p[i-1]=='?')
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
        }
        else
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
    bool result=isMatch("", "*");
    return 0;
}
