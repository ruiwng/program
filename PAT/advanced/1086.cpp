#include  <stdio.h>
#include  <string.h>
#include  <stack>
using namespace std;

struct tree_node
{
    unsigned int element;
    tree_node *left_child;
    tree_node *right_child;
    tree_node(unsigned int e):element(e),left_child(NULL),right_child(NULL){
        
    }
};

void post_order(tree_node* head,bool& first)
{
    if(head!=NULL)
    {
        if(head->left_child!=NULL)
            post_order(head->left_child,first);
        if(head->right_child!=NULL)
            post_order(head->right_child,first);
        if(first)
            first=false;
        else
            printf(" ");
        printf("%u",head->element);
    }
}

int main()
{
    unsigned int node_count;
    while(scanf("%u",&node_count)!=EOF)
    {
        char str[30];
        getchar();
        stack<tree_node*> pointer_stack;
        tree_node* head=NULL;
        tree_node* current_node=NULL;
        bool pop=false;
        unsigned int count=0;
        while(true)
        {
            fgets(str,30,stdin);
            if(strncmp(str,"Pop",3)==0)
            {
                current_node=pointer_stack.top();
                pointer_stack.pop();
                pop=true;
            }
            else
            {
                char *p=str+5;
                unsigned int temp;
                sscanf(p,"%u",&temp);
                if(current_node==NULL)
                {
                    current_node=new tree_node(temp);
                    head=current_node;
                }
                else if(!pop)
                {
                    current_node->left_child=new tree_node(temp);
                    current_node=current_node->left_child;
                }
                else
                {
                    current_node->right_child=new tree_node(temp);
                    current_node=current_node->right_child;
                }
                pop=false;
                pointer_stack.push(current_node);
                ++count;
            }
            if(count==node_count&&pointer_stack.empty())
                break;
        }
        bool first=true;
        post_order(head,first);
        printf("\n");
    }
    return 0;
}
