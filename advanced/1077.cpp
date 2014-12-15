#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
int main()
{
	 unsigned int n;
	 vector<string> strVec;
	 while(scanf("%u",&n)!=EOF)
	 {
		 getchar();
		 while(!strVec.empty())
			 strVec.pop_back();
		 for(unsigned int i=0;i<n;i++)
		 {
			 char ch[260];
			 fgets(ch,260,stdin);
			 int m=strlen(ch);
			 if(ch[m-1]=='\n')
				 ch[m-1]='\0';
			 string strTemp(ch);
			 strVec.push_back(strTemp);
		 }
		 unsigned int x=strVec[0].size();
		 for(vector<string>::const_iterator iter=strVec.begin();iter!=strVec.end();++iter)
		 {
			 if(iter->size()<x)
				 x=iter->size();
		 }
		 unsigned int i=0;
		 while(i<x)
		 {
			 bool temp=true;
			 for(unsigned int m=1;m<strVec.size();m++)
			 {
				 if(strVec[0][strVec[0].size()-i-1]!=strVec[m][strVec[m].size()-i-1])
				 {
					 temp=false;
					 break;
				 }
			 }
			 if(temp)
				 i++;
			 else
				 break;
		 }
		 if(i==0)
			 printf("nai");
		 else
			 for(unsigned int k=strVec[0].size()-i;k<strVec[0].size();k++)
				 printf("%c",strVec[0][k]);
		 //printf("\n");
	 }
	 return 0;
}