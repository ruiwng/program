#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
using namespace std;

struct poke
{
    int value;
    char suit;
    poke(int v=0,char s=0):value(v),suit(s){
        
    }
    bool operator<(const poke& p) const
    {
        return this->value<p.value;
    }
};

poke black[5];
poke white[5];


bool high_card(const poke* p,int* value)
{
    for(int i=0;i<5;++i)
        value[i]=p[4-i].value;
    return true;
}


bool is_pair(const poke* p,int* value)
{
    int i;
    for(i=0;i<4;++i)
    {
         if(p[i].value==p[i+1].value)
        {
            value[0]=p[i].value;
            break;
        }
    }       
    if(i==4)
        return false;
    int k=1;
    for(int j=4;j>0;)
    {
        if(p[j].value!=p[j-1].value)
        {
             value[k++]=p[j].value;
             --j;
        }
        else
            j-=2;
    }
    return true;         
}

bool two_pair(const poke* p,int* value)
{
    int k=0;
    for(int i=4;i>0;)
    {
        if(p[i].value==p[i-1].value)
        {
            value[k++]=p[i].value;
            i-=2;
        }
        else
        {
            value[2]=p[i].value;
            --i;
        }
    }
    if(k==2)
        return true;
    else
        return false;
}


bool three_a_kind(const poke* p,int* value)
{
    if(p[2].value==p[4].value)
    {
        value[0]=p[2].value;
        return true;
    }
    if(p[1].value==p[3].value)
    {
        value[0]=p[1].value;
        return true;
    }
    if(p[0].value==p[2].value)
    {
        value[0]=p[0].value;
        return true;
    }
    return false;
}

bool straight(const poke* p,int* value)
{
    for(int i=0;i<4;++i)
        if(p[i].value+1!=p[i+1].value)
            return false;
    value[0]=p[4].value;
    return true;
}

bool flush(const poke* p,int* value)
{
    for(int i=0;i<4;++i)
        if(p[i].suit!=p[i+1].suit)
            return false;
    return high_card(p,value);
}

bool full_house(const poke* p,int* value)
{
    if(p[0].value==p[2].value&&p[3].value==p[4].value)
    {
        value[0]=p[0].value;
        return true;
    }
    if(p[2].value==p[4].value&&p[0].value==p[1].value)
    {
        value[0]=p[2].value;
        return true;
    }
    return false;
}

bool four_a_kind(const poke* p,int* value)
{
    if(p[1].value==p[4].value)
    {
        value[0]=p[1].value;
        return true;
    }
    if(p[0].value==p[3].value)
    {
        value[0]=p[0].value;
        return true;
    }
    return false;
}

bool straight_flush(const poke* p,int* value)
{
    if(!straight(p,value))
        return false;
    return flush(p,value);
}

typedef bool (*func)(const poke* p,int* value);

func func_array[9]=
    {
        straight_flush,four_a_kind,full_house,flush,
        straight,three_a_kind,two_pair,is_pair,high_card
    };


int main()
{
    int index=0;
    char str[3];
    while(scanf("%s",str)!=EOF)
    {
        poke *p;
        int k;
        if(index<5)
        {
            k=index;
            p=black;
        }
        else
        {
            k=index-5;
            p=white;
        }
        if(str[0]>='2'&&str[0]<='9')
            p[k].value=str[0]-'0';
        else if(str[0]=='T')
                p[k].value=10;
        else if(str[0]=='J')
                p[k].value=11;
        else if(str[0]=='Q')
                p[k].value=12;
        else if(str[0]=='K')
                p[k].value=13;
        else if(str[0]=='A')
                p[k].value=14;
        p[k].suit=str[1];
        ++index;
        if(index==10)
        {
            index=0;
            sort(black,black+5);
            sort(white,white+5);
            int black_value[5];
            int white_value[5];

            int black_level;
            int white_level;
            for(int i=0;i<10;++i)
            {
               memset(black_value,0,sizeof(black_value));
               if(func_array[i](black,black_value))
              {
                black_level=i;
                break;
              }
            }

            for(int i=0;i<10;++i)
           {
               memset(white_value,0,sizeof(white_value));
              if(func_array[i](white,white_value))
              {
                white_level=i;
                break;
              }
           }
           if(black_level!=white_level)
           {
              if(black_level<white_level)
                printf("Black wins.\n");
              else
                printf("White wins.\n");
           }
           else
           {
              int j=0;
              for(j=0;j<5;++j)
              {
                if(black_value[j]!=white_value[j])
                {
                    if(black_value[j]>white_value[j])
                        printf("Black wins.\n");
                    else
                        printf("White wins.\n");
                    break;
                }                
              }
            if(j==5)
                printf("Tie.\n");
           }        
        }    
    }
    return 0;
}
