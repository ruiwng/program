#include  <stdio.h>
#include  <string.h>

struct scale
{
    char left[10];
    char right[10];
    char result[10];
};

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int j=0;j<n;++j)
        {
             scale s[3];
             for(int i=0;i<3;++i)
             scanf("%s%s%s",s[i].left,s[i].right,s[i].result);
             int record[20];
             memset(record,0,sizeof(record));
             int light_array[20];
             int heavy_array[20];
             memset(light_array,0,sizeof(light_array));
             memset(heavy_array,0,sizeof(heavy_array));
             int k=0;
             for(int i=0;i<3;++i)
             {
                if(strcmp(s[i].result,"even")==0)
                {
                    char* p=s[i].left;
                    while(*p!='\0')
                       record[*p++-'A']=1;
                    p=s[i].right;
                   while(*p!='\0')
                    record[*p++-'A']=1;
                 }
                else if(strcmp(s[i].result,"down")==0)
                {
                    ++k;
                    char* p=s[i].left;
                    while(*p!='\0')
                        ++light_array[*p++-'A'];
                    p=s[i].right;
                    while(*p!='\0')
                        ++heavy_array[*p++-'A'];
                }
                else
                {
                    ++k;
                    char* p=s[i].left;
                    while(*p!='\0')
                        ++heavy_array[*p++-'A'];
                    p=s[i].right;
                    while(*p!='\0')
                        ++light_array[*p++-'A'];
                }
              }
              char object;
              char str[10];
              bool success=false;
              for(int i=0;i<3;++i)
              {
                 int c=0;
                 if(strcmp(s[i].result,"even")!=0)
                 {
                     char* p=s[i].left;
                     while(*p!='\0')
                     {
                         if(record[*p-'A']!=1)
                         {
                            if(++c==1)
                           {
                              object=*p;
                              if(strcmp(s[i].result,"up")==0)
                                strcpy(str,"heavy");
                              else
                                strcpy(str,"light");
                            }                  
                          }  
                          ++p;
                      }
                      p=s[i].right;
                      while(*p!='\0')
                      {
                         if(record[*p-'A']!=1)
                         {
                            if(++c==1)
                            {
                               object=*p;
                               if(strcmp(s[i].result,"up")==0)
                                  strcpy(str,"light");
                               else
                                  strcpy(str,"heavy");
                             }
                         }
                          ++p;
                       }
                   }
                   if(c==1)
                   {
                       success=true;
                       break;
                   }
                       
               }
              if(!success)
              {
                  for(int i=0;i<12;++i)
                  {
                      if(light_array[i]==k&&record[i]!=1)
                      {
                          success=true;
                          object='A'+i;
                          strcpy(str,"light");
                          break;
                      }
                  }
              }
              if(!success)
              {
                  for(int i=0;i<12;++i)
                  {
                      if(heavy_array[i]==k&&record[i]!=1)
                      {
                          object='A'+i;
                          strcpy(str,"heavy");
                          break;
                      }
                  }
              }
             printf("%c is the counterfeit coin and it is %s.\n",object,str);
        }       
    }
    return 0;
}
