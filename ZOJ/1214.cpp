#include  <stdio.h>
#include  <string.h>
#include  <deque>
#include  <string>
#include  <map>
using namespace std;

struct prepare
{
    int day;
    int quantity;
    prepare(int d=0,int q=0):day(d),quantity(q){
        
    }
};
map<string,deque<prepare> > dish_info;
void print_day(int day_number)
{
    printf("\nFrozen dishes at the end of day%4d:\n",day_number);
    printf("Dish                     Prepared on day  Quantity\n");
    printf("==================================================\n");
    for(map<string,deque<prepare> >::iterator iter=dish_info.begin();iter!=dish_info.end();++iter)
    {
        const deque<prepare>& ref=iter->second;
        int len=ref.size();
        int start=0;
        bool first=true;
        while(start<len&&ref[start].day<=day_number)
        {
            printf("%-30s%10d%10d\n",first?iter->first.c_str():"",ref[start].day,ref[start].quantity);
            first=false;
            ++start;
        }
    }
}

void erase_dish(const string& dish_name,int q,int d)
{
    map<string,deque<prepare> >::iterator iter=dish_info.find(dish_name);
    deque<prepare>& ref=iter->second;
    for(deque<prepare>::iterator iter_ref=ref.begin();iter_ref!=ref.end();++iter_ref)
    {
        if(iter_ref->day==d)
        {
            if(iter_ref->quantity>=q)
            {
                iter_ref->quantity-=q;
                if(iter_ref->quantity==0)
                    ref.erase(iter_ref);
                return;
            }
            else
            {
                q-=iter_ref->quantity;
                ref.erase(iter_ref);
                break;
            }
        }
    }
    while(!ref.empty()&&ref.front().quantity<=q)
    {
        q-=ref.front().quantity;
        ref.pop_front();
    }
    if(q!=0)
        ref.front().quantity-=q;
}

int main()
{
    char str[100];
    int last_day;
    while(fgets(str,100,stdin)!=NULL)
    {
        str[strlen(str)-1]='\0';
        char *p=str;
        while(*p==' ')
            ++p;
        int prepare_day;
        sscanf(p,"%d",&prepare_day);
        if(prepare_day==-1)
            break;
        last_day=prepare_day;
        p=strchr(p,' ');
        while(*p==' ')
            ++p;
        int prepare_quantity;
        sscanf(p,"%d",&prepare_quantity);
        p=strchr(p,' ');
        while(*p==' ')
            ++p;
        dish_info[p].push_back(prepare(prepare_day,prepare_quantity));
    }
    printf("Problem 8 by team x\n");
    int prev_day=1;
    int sold_day;
    while(fgets(str,100,stdin)!=NULL)
    {
        str[strlen(str)-1]='\0';
        char* p=str;
        while(*p==' ')
            ++p;
        sscanf(p,"%d",&sold_day);
        while(sold_day>prev_day)
            print_day(prev_day++);

        p=strchr(p,' ');
        while(*p==' ')
            ++p;
        int sold_quantity;
        sscanf(p,"%d",&sold_quantity);
        p=strchr(p,' ');
        while(*p==' ')
            ++p;
        erase_dish(p,sold_quantity,sold_day);
    }
    if(sold_day>last_day)
        last_day=sold_day;
    while(prev_day<=last_day)
        print_day(prev_day++);
    printf("End of problem 8 by team x\n");
    return 0;
}
