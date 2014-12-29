#include  <stdio.h>
#include  <string.h>

char matrix[101][101];

int directions[8][2]=
    {
        {1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}
    };

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            if(i!=0)
                printf("\n");
            int length;
            scanf("%d",&length);
            for(int j=0;j<length;++j)
                scanf("%s",matrix[j]);

            char dest[110];
            while(scanf("%s",dest)!=EOF)
            {
                
                if(strcmp(dest,"0")==0)
                    break;
                bool success=false;
                for(int j=0;!success&&j<length;++j)
                {
                    for(int k=0;!success&&k<length;++k)
                    {
                        if(matrix[j][k]==dest[0])
                        {
                             for(int m=0;!success&&m<8;++m)
                             {
                                 int x=j;
                                 int y=k;
                                 char* p=dest;
                                 while(true)
                                 {
                                     if(*p!=matrix[x][y])
                                         break;
                                     if(*++p=='\0') break;
                                     x+=directions[m][0];
                                     y+=directions[m][1];
                                     if(x<0||x>=length||y<0||y>=length)
                                         break;
                                 }
                                 if(*p=='\0')
                                 {
                                     printf("%d,%d %d,%d\n",j+1,k+1,x+1,y+1);
                                     success=true;
                                 }
                             }
                        }
                       
                    }
                }
                if(!success)
                    printf("Not found\n");
            }
        }
    }
    return 0;
}
