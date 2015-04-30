#include  <string.h>

bool isIsomorphic(char* s, char* t) {
	char record[260];   
	char info[250];
	memset(record,0,sizeof(record));
	memset(info,0,sizeof(info));
	while(*s!='\0')
	{
		if(record[*s]==0)
		{
			if(info[*t]==1)
				return false;
			record[*s]=*t;
			info[*t]=1;
		}
		else if(record[*s]!=*t)
			return false;
		++s;
		++t;
	}
	return true;
}

int main()
{

}