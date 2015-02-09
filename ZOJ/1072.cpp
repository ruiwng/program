#include  <stdio.h>

inline int get_address(char *p)
{
    int result=0;
    for(int i=0;i<2;++i)
    {
        result<<=4;
        if(p[i]>='0'&&p[i]<='9')
            result+=p[i]-'0';
        else
            result+=p[i]-'A'+10;
    }
    return result;
}

int main()
{
    char memory[260];
    while(scanf("%s",memory)!=EOF)
    {
        char *p=memory;
        if(*p=='8')
            break;
        int a_accumulator=0;
        int b_accumulator=0;
        bool stop=false;
        while(!stop)
        {
            switch(*p)
            {
            case '0':
                {
                    char temp=memory[get_address(p+1)];
                    if(temp>='0'&&temp<='9')
                        a_accumulator=temp-'0';
                    else
                        a_accumulator=temp-'A'+10;
                    p+=3;
                    break;                    
                }
            case '1':
                {
                    int pos=get_address(p+1);
                    if(a_accumulator>=0&&a_accumulator<=9)
                        memory[pos]='0'+a_accumulator;
                    else
                        memory[pos]='A'+a_accumulator-10;
                    p+=3;
                    break;
                }
            case '2':
                {
                    int temp=a_accumulator;
                    a_accumulator=b_accumulator;
                    b_accumulator=temp;
                    ++p;
                    break;
                }
            case '3':
                {
                    int temp=a_accumulator+b_accumulator;
                    a_accumulator=temp%16;
                    b_accumulator=temp/16;
                    ++p;
                    break;
                }
            case '4':
                {
                    if(++a_accumulator==16)
                        a_accumulator=0;
                    ++p;
                    break;
                }
            case '5':
                {
                    if(--a_accumulator==-1)
                        a_accumulator=15;
                    ++p;
                    break;
                }
            case '6':
                {
                    if(a_accumulator==0)
                        p=memory+get_address(p+1);
                    else
                        p+=3;
                    break;
                }
            case '7':
                p=memory+get_address(p+1);
                break;
            case '8':
                stop=true;
                break;
            default:
                break;
            }
        }
        printf("%s\n",memory);
    }
    return 0;
}
