#include  <stdlib.h>
#include  <string.h>

char *convert(char *s, int nRows) {
	int len=strlen(s);
	int width;
	if(nRows==1)
		width=2*len;
	else
		width=len/(nRows-1)+2;
	char *result=(char*)malloc(width*nRows);
	int size=width*nRows;
	memset(result,' ',size);
	int column=0;
	while(true)
	{
		int index=0;
		while(*s!='\0'&&index<nRows)
			result[(index++)*width+column]=*s++;
		if(*s=='\0')
			break;
		index=nRows-2;
		++column;
		while(*s!='\0'&&index>0)
			result[(index--)*width+column]=*s++;
		if(*s=='\0')
			break;
		++column;
	}
	int pos=0;
	for(int i=0;i<size;++i)
	{
		if(result[i]!=' ')
			result[pos++]=result[i];
	}
	result[pos]='\0';
	return result;
}

int main()
{
	char *r=convert("PAYPALISHIRING",1);
	return 0;
}