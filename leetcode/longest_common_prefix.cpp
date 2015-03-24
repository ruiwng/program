#include  <stdlib.h>
#include  <string.h>

char *longestCommonPrefix(char *strs[], int n) {
    int length=0;
	if(n!=0)
	{
		while(true)
		{
			if(strs[0][length]=='\0')
				break;
			int i=1;
			for(;i<n;++i)
			{
				if(!(strs[i][length]!='\0'&&strs[i][length]==strs[0][length]))
					break;
			}
			if(i==n)
				++length;
			else
				break;
		}
	}
	
	char *p=(char*)malloc(length+1);
	memset(p,0,length+1);
	if(n!=0)
	    strncpy(p,strs[0],length);
	return p;
}

int main()
{

}