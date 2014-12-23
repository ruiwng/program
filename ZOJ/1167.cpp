#include  <stdio.h>
#include  <string.h>
#include  <queue>
using namespace std;

struct tree_node
{
    int element;
    tree_node *left_child;
    tree_node* right_child;
    tree_node(int e=0,tree_node* l=NULL,tree_node* r=NULL):element(e),left_child(l),right_child(r){
        
    }
};

bool insert_flag;

void insert_node(tree_node*& n,int e,char* p)
{
    if(*p=='\0')
    {
        if(n==NULL)
            n=new tree_node(e);
        else if(n->element==0)
            n->element=e;
        else
            insert_flag=false;
    }
    else if(*p=='L')
    {
        if(n==NULL)
            n=new tree_node;
        insert_node(n->left_child,e,p+1);
    }
    else if(*p=='R')
    {
        if(n==NULL)
            n=new tree_node;
        insert_node(n->right_child,e,p+1);
    }
}

int arry[300];

bool layer_traversed(tree_node* root)
{
    int index=0;
    queue<tree_node*> node_queue;
    node_queue.push(root);
    while(!node_queue.empty())
    {
        tree_node* t=node_queue.front();
        if(t->element==0)
            return false;
        node_queue.pop();
        arry[index++]=t->element;
        if(t->left_child!=NULL)
            node_queue.push(t->left_child);
        if(t->right_child!=NULL)
            node_queue.push(t->right_child);
    }
    return true;
}

int main()
{
    char str[3000];
    tree_node* root=NULL;
    int node_number=0;
    bool flag=false;
    insert_flag=true;
    while(fgets(str,3000,stdin)!=NULL)
    {
        char *p=str;
        while(true)
        {
            p=strchr(p,'(');
            if(p==NULL)
                break;
            ++p;
            if(*p==')')
            {
                flag=true;
                break;
            }
            int data;
            sscanf(p,"%d",&data);
            while(*p!='L'&&*p!='R'&&*p!=')')
                ++p;
            char temp[300];
            memset(temp,0,sizeof(temp));
            int index=0;
            while(*p=='L'||*p=='R')
                temp[index++]=*p++;
            ++node_number;
            if(insert_flag)
               insert_node(root,data,temp);
        }
        if(flag)
        {
            if(!insert_flag||!layer_traversed(root))
                printf("not complete\n");
            else
            {
                for(int i=0;i<node_number;++i)
                    printf("%d%c",arry[i],i==node_number-1?'\n':' ');
            }
            flag=false;
            root=NULL;
            node_number=0;
            insert_flag=true;
        }
    }
    return 0;
}
