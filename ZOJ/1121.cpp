#include  <stdio.h>
#include  <string.h>
#include  <list>
#include  <map>
#include  <string>
using namespace std;

struct book
{
    string name;
    int number;
    book(const string s="",int n=0):name(s),number(n){
        
    }
};

list<book> book_array;
int available_space;
map<string,int> book_checkout;

void print_book()
{
    for(list<book>::iterator iter=book_array.begin();iter!=book_array.end();++iter)
        printf("%s%*d\n",iter->name.c_str(),static_cast<int>(34-iter->name.size()),iter->number);
    printf("AVAILABLE SHELF SPACE:%*d\n\n",static_cast<int>(34-strlen("AVAILABLE SHELF SPACE:")),available_space);
}

int main()
{
    while(scanf("%d",&available_space)!=EOF)
    {
        getchar();
        char str[300];
        printf("Program 2 by team X\n");
        while(fgets(str,300,stdin)!=NULL)
        {
            char* p=str;
            if(strncmp(p,"PRINT",5)==0)
                print_book();
            else if(strncmp(p,"ADD",3)==0)
            {
                p+=9;
                char* q=p+29;
                book temp;
                char* t=q-1;
                while(*t==' ')
                    --t;
                *(t+1)='\0';
                temp.name=p;
                sscanf(q,"%d",&temp.number);
                while(available_space<temp.number)
                {
                    available_space+=book_array.rbegin()->number;
                    book_array.pop_back();
                }
                book_array.push_front(temp);
                available_space-=temp.number;
            }
            else if(strncmp(p,"CHECKOUT",8)==0)
            {
                p+=9;
                char* q=strchr(p,'\n');
                --q;
                while(*q==' ')
                    --q;
                *(q+1)='\0';
                for(list<book>::iterator iter=book_array.begin();iter!=book_array.end();++iter)
                {
                    if(iter->name==p)
                    {
                        available_space+=iter->number;
                        book_checkout.insert(make_pair(p,iter->number));
                        book_array.erase(iter);
                        break;
                    }
                }
            }
            else if(strncmp(p,"RETURN",6)==0)
            {
                p+=9;
                char* q=strchr(p,'\n');
                --q;
                while(*q==' ')
                    --q;
                *(q+1)='\0';
                map<string,int>::iterator iter=book_checkout.find(p);
                while(available_space<iter->second)
                {
                    available_space+=book_array.rbegin()->number;
                    book_array.pop_back();
                }
                book_array.push_front(book(p,iter->second));
                book_checkout.erase(iter);
                available_space-=iter->second;
            }
        }
        printf("End of program 2 by team X\n");
    }
    return 0;
}
