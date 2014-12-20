#include  <stdio.h>
#include  <string.h>
#include  <queue>
#include  <vector>
#include  <functional>
#include  <algorithm>
using namespace std;

int weight[256];

struct info
{
    char ch;
    char encode[100];
    int length;
};

struct node
{
    int weight;
    node* left_child;
    node* right_child;
    node(int w=0,node* l=NULL,node* r=NULL):weight(w),left_child(l),right_child(r){
        
    }
    bool operator>(const node& n) const
    {
        return this->weight>n.weight;
    }
};

struct comp_func
{
    bool operator()(const node* lhs,const node* rhs) const
    {
       return *lhs>*rhs;
    }
};

int min_weight;
int weight_func(node* n,int level)
{
    if(n->left_child==NULL&&n->right_child==NULL)
        min_weight+=n->weight*level;
    if(n->left_child!=NULL)
        weight_func(n->left_child,level+1);
    if(n->right_child!=NULL)
        weight_func(n->right_child,level+1);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        priority_queue<node*,vector<node*>,comp_func> weight_queue;
        memset(weight,0,sizeof(weight));
        for(int i=0;i<n;++i)
        {
            char str[3];
            int w;
            scanf("%s %d",str,&w);
            weight[str[0]]=w;
            weight_queue.push(new node(w));
        }
        while(weight_queue.size()>1)
        {
            node* node1=weight_queue.top();
            weight_queue.pop();
            node* node2=weight_queue.top();
            weight_queue.pop();
            weight_queue.push(new node(node1->weight+node2->weight,node1,node2));
        }
        node* root=weight_queue.top();
        min_weight=0;
        weight_func(root,0);
        int sub_num;
        scanf("%d",&sub_num);
        for(int i=0;i<sub_num;++i)
        {
            bool success=true;
            int current_weight=0;
            vector<info> info_array;
            for(int j=0;j<n;++j)
            {
                 char str1[3],str2[1000];
                 scanf("%s %s",str1,str2);
                 if(!success)
                     continue;
                 info info_temp;
                 info_temp.ch=str1[0];
                 strcpy(info_temp.encode,str2);
                 info_temp.length=strlen(str2);
                 current_weight+=weight[str1[0]]*info_temp.length;
                 for(int k=0;k<j;++k)
                 {
                     if(strncmp(info_array[k].encode,str2,min(info_array[k].length,info_temp.length))==0)
                     {
                         success=false;
                         break;
                     }
                 }
                 info_array.push_back(info_temp);
            }
            if(success&&current_weight==min_weight)
                printf("Yes\n");
            else
                printf("No\n");
        }
        
    }
    return 0;
}
