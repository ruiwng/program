#include  <string.h>
#include  <stdio.h>

class Solution {
public:
    bool isNumber(const char *s) {
        const char* p=s;
		int dot_count=0;
		int e_count=0;
		while(*p==' ')
			++p;
		if(*p=='+'||*p=='-')
			++p;
		while(*p!=' '&&*p!='\0')
		{
			if((*p>='0'&&*p<='9')||*p=='.'||*p=='e')
			{
				if(*p=='.')
				{
					if(++dot_count>1)
						return false;
				}
				else if(*p=='e')
				{
					if(++e_count>1)
						return false;
				}
			}
			else if(!((*p=='+'||*p=='-')&&(*(p-1)=='e')))
				return false;
		  ++p;
		}
		while(*p==' ')
			++p;
		if(*p!='\0')
			return false;
		p=s;
		while(*p!='\0')
		{
			if(*p=='e')
				break;
			++p;
		}
		double temp;
		if(sscanf(s,"%lf",&temp)!=1)
			return false;
		else if(*p!='\0')
		{
			const char* q=p;
			while(*q!='\0')
			{
				if(*q=='.')
					return false;
				++q;
			}
			if(sscanf(p+1,"%lf",&temp)!=1)
				return false;
			else
				return true;
		}
		else
		   return true;
    }
};

int main()
{
	Solution s;
	bool result=s.isNumber("6e6.5");
	return 0;
}