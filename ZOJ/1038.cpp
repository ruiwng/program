#include  <stdio.h>
#include  <queue>
#include  <string>
using namespace std;

const char *relative_chars[10]={
    "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};

struct node
{
    int probability;
    node *next;
    node(int p=0,node *n=NULL)
        :probability(p),next(n){}
};

struct record
{
    node* next_pos;
    string current_word;
    record(node *n=NULL,string c="")
        :next_pos(n),current_word(c){}
};

int main()
{
    int scenarios;
    while(scanf("%d",&scenarios)!=EOF)
    {
        for(int i=0;i<scenarios;++i)
        {
            printf("Scenario #%d:\n",i+1);
            node *dictionary=new node;
            int word_count;
            scanf("%d",&word_count);
            for(int j=0;j<word_count;++j)
            {
                char str[110];
                int p;
                scanf("%s%d",str,&p);
                char *q=str;
                node *k=dictionary;
                while(*q!='\0')
                {
                    if(k->next==NULL)
                        k->next=new node[26];
                    node *temp=k->next;
                    temp[*q-'a'].probability+=p;
                    k=&temp[*q-'a'];
                    ++q;
                }
            }
            int query_number=0;
            scanf("%d",&query_number);
            for(int j=0;j<query_number;++j)
            {
                char str[1000];
                scanf("%s",str);
                char *q=str;
                queue<record> node_queue;
                node_queue.push(record(dictionary->next));
                while(*q!='1')
                {
                    if(!node_queue.empty())
                    {
                        int max_probability=0;
                        string max_pos;
                        int len=node_queue.size();
                        for(int k=0;k<len;++k)
                        {                             
                            node *current_node=node_queue.front().next_pos;
                            if(current_node!=NULL)
                            {
                                const char *t=relative_chars[*q-'0'];
                                while(*t!='\0')
                                {
                                    if(current_node[*t-'a'].probability!=0)
                                    {
                                        node_queue.push(record(current_node[*t-'a'].next,node_queue.front().current_word+string(1,*t)));
                                        if(current_node[*t-'a'].probability>max_probability)
                                        {
                                            max_probability=current_node[*t-'a'].probability;
                                            max_pos=node_queue.front().current_word+string(1,*t);
                                        }
                                    }
                                    ++t;
                                }
                            }
                            node_queue.pop();
                        }
                        if(max_probability==0)
                            printf("MANUALLY\n");
                        else
                            printf("%s\n",max_pos.c_str());
                    }
                    else
                        printf("MANUALLY\n");
                    ++q;
                }
                printf("\n");
            }
            printf("\n");
        }
        
    }
    return 0;
}

                
                    
            
