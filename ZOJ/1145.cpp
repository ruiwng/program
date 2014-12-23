#include  <stdio.h>
#include  <string.h>
#include  <vector>
using namespace std;

int get_value(char* p)
{
    int result;
    if(*p!='(')
    {
        sscanf(p,"%d",&result);
        while(*p!='+'&&*p!='-'&&*p!='*'&&*p!='\0')
            ++p;
        if(*p=='\0')
            return result;
    }
    else
    {
		++p;
		char t[100];
		int index=0;
		memset(t,0,sizeof(t));
		int num=0;
		while(true)
		{
			if(*p=='(')
				++num;
			else if(*p==')')
			{
				--num;
				if(num==-1)
					break;
			}
			t[index++]=*p++;
		}
		++p;
		result=get_value(t);
    }
    while(true)
    {
        if(*p=='\0')
            break;
        char oper=*p;
        ++p;
        int temp;
        if(*p!='(')
        {
            sscanf(p,"%d",&temp);
            while(*p!='+'&&*p!='-'&&*p!='*'&&*p!='\0')
                ++p;
        }
        else
        {
            ++p;
            char t[100];
            int index=0;
            memset(t,0,sizeof(t));
			int num=0;
			while(true)
			{
				if(*p=='(')
					++num;
				else if(*p==')')
				{
					--num;
					if(num==-1)
						break;
				}
				t[index++]=*p++;
			}
            ++p;
            temp=get_value(t);
        }
        switch(oper)
        {
          case '+':
             result+=temp;
             break;
          case '-':
            result-=temp;
            break;
          case '*':
            result*=temp;
            break;
        }
    }
    return result;
}

int main()
{
    char str[100];
    int equation_number=0;
    while(fgets(str,100,stdin)!=NULL)
    {
        str[strlen(str)-1]='\0';
        if(strcmp(str,"0")==0)
            break;
        printf("Equation #%d:\n",++equation_number);
        char* p=str;
        int result;
        sscanf(p,"%d",&result);
        p=strchr(p,'=');
        ++p;
        while(*p==' ')
            ++p;
        char dest[100];
        memset(dest,0,sizeof(dest));

        int num=0;
        char* q=dest;
        vector<int> pos;
        while(*p!='\0')
        {
			if(*p==' ')
			{
				if(*(q-1)!='(')
					*q++=' ';
				while(*p==' ')
					++p;
			}
			else if(*p=='(')
			{
				if(*(q-1)!='('&&*(q-1)!=' '&&q!=dest)
					*q++=' ';
				*q++='(';
				++p;
			}
			else if(*p==')')
			{
				if(*(q-1)==' ')
					*(q-1)=')';
				else
					*q++=')';
				++p;
			}
			else
			{
				if(*(q-1)==')')
					*q++=' ';
				*q++=*p++;
			}              
        }
		q=dest;
		if(dest[strlen(dest)-1]==' ')
			dest[strlen(dest)-1]='\0';
        while(*q!='\0')
        {
            if(*q==' ')
            {
                pos.push_back(q-dest);
                ++num;
            }
            ++q;
        }
        vector<int> oper_array(num,0);
        bool success=false;
        while(true)
        {
            for(int i=0;i<num;++i)
            {
                if(oper_array[i]==0)
                    dest[pos[i]]='+';
                else if(oper_array[i]==1)
                    dest[pos[i]]='-';
                else
                    dest[pos[i]]='*';
            }
            int current_value=get_value(dest);
            if(current_value==result)
            {
                success=true;
                printf("%d=%s\n\n",result,dest);
                break;
            }
            int j=0;
            while(j<num)
            {
                if(++oper_array[j]==3)
                {
                    oper_array[j]=0;
                    ++j;
                }
                else
                    break;
            }
            if(j==num)
                break;
        }
        if(!success)
            printf("Impossible\n\n");
    }
    return 0;
}
