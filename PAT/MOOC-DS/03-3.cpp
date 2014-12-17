#include  <stdio.h>
#include  <string.h>
#include  <stack>
using namespace std;
struct tree_node
{
    int element;
    tree_node* left_child;
    tree_node* right_child;
    tree_node(int e=0,tree_node* l=NULL,tree_node* r=NULL):element(e),left_child(l),right_child(r){}
};

bool first;
void post_order(tree_node* node)
{
    if(node==NULL)
        return;
    post_order(node->left_child);
    post_order(node->right_child);
    if(first)
        first=false;
    else
        printf(" ");
    printf("%d",node->element);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        n=n*n;
        tree_node* root=NULL;
        tree_node* current_node=NULL;
        bool left=true;
        stack<tree_node*> node_stack;
        for(int i=0;i<n;++i)
        {
            char str[5];
            scanf("%s",str);
            if(strcmp(str,"Push")==0)
            {
                int element;
                scanf("%d",&element);
                tree_node* node_temp=new tree_node(element);
                if(root==NULL)
                    root=node_temp;
                else if(left)
                    current_node->left_child=node_temp;
                else
                {
                     current_node->right_child=node_temp;
                     left=true;
                }
                 current_node=node_temp;
                 node_stack.push(current_node);
            }
            else
            {
                current_node=node_stack.top();
                left=false;
                node_stack.pop();
            }

        }
        first=true;
        post_order(root);
        printf("\n");
    }
    return 0;
}
