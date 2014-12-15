/*
#include  <iostream>
#include  <string>
using namespace std;

int main()
{
	string str1,str2;
	while(getline(cin,str1))
	{
		getline(cin,str2);
		size_t pos=str1.find(str2);
		while(pos!=string::npos)
		{
			str1.erase(pos,str2.length());
			pos=str1.find(str2);
		}
		cout<<str1<<endl;
	}
}*/

#include  <stdio.h>
#include  <string.h>

int main()
{
	char str1[90],str2[90];
	while(fgets(str1,90,stdin)!=NULL)
	{
		fgets(str2,90,stdin);
	    unsigned int length1=strlen(str1);
	    if(str1[length1-1]=='\n')
	    {
		   str1[length1-1]='\0';
		   --length1;
	    }
	    unsigned int length2=strlen(str2);
	    if(str2[length2-1]=='\n')
	    {
		   str2[length2-1]='\0';
		   --length2;
	    }
	    char *p=strstr(str1,str2);
	    while(p!=NULL)
	    {
		   char* q=p+length2;
		   while((*p++=*q++)!='\0');
		   p=strstr(str1,str2);
	    }
	    printf("%s\n",str1);	
	}
	return 0;
}

