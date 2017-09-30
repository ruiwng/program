#include  <stdio.h>
#include  <algorithm>
#include  <set>
using namespace std;


int pre_order[40];
int post_order[40];
int in_order[40];
int in_order_sequence;

struct tree_node
{
    int value;
    tree_node *left_child, *right_child;
    tree_node(int value, tree_node *left_child=NULL, tree_node *right_child=NULL): value(value), left_child(left_child), right_child(right_child){}
};

pair<tree_node*, int> generate_tree(int pre_start, int pre_end, int post_start, int post_end)
{
    if(pre_start > pre_end)
        return pair<tree_node*, int>(NULL, 1);
    else if(pre_start == pre_end)
        return pair<tree_node*, int>(new tree_node(pre_order[pre_start]), 1);
    else if(pre_order[pre_start] != post_order[post_end])
        return pair<tree_node*, int>(NULL, 0);
    else
    {
        tree_node *root = NULL;
        int i = 0;
        set<int> num_set;
        while(true)
        {
            if(num_set.empty())
            {
                pair<tree_node*, int> left_tree = generate_tree(pre_start + 1, pre_start + i, post_start, post_start + i - 1);
                pair<tree_node*, int> right_tree = generate_tree(pre_start + i + 1, pre_end, post_start + i, post_end - 1);
                if(left_tree.second != 0 && right_tree.second != 0)
                {
                    if(root == NULL)
                    {
                        root = new tree_node(pre_order[pre_start], left_tree.first, right_tree.first);
                        if(left_tree.second > 1 || right_tree.second > 1)
                            return pair<tree_node*, int>(root, 2);
                    }
                    else
                        return pair<tree_node*, int>(root, 2);
                }
            }
            ++i;
            if(pre_start + i > pre_end)
                break;
            if(num_set.find(pre_order[pre_start + i]) == num_set.end())
                num_set.insert(pre_order[pre_start + i]);
            else
                num_set.erase(pre_order[pre_start + i]);
            if(num_set.find(post_order[post_start + i - 1]) == num_set.end())
                num_set.insert(post_order[post_start + i - 1]);
            else
                num_set.erase(post_order[post_start + i - 1]);
        }
        if(root == NULL)
            return pair<tree_node*, int>(NULL, 0);
        else
            return pair<tree_node*, int>(root, 1);
    }
}

void in_order_traverse(tree_node* root)
{
        if(root->left_child != NULL)
            in_order_traverse(root->left_child);
        in_order[in_order_sequence++] = root->value;
        if(root->right_child != NULL)
            in_order_traverse(root->right_child);
}

int main()
{
    int num;
    while(scanf("%d", &num) != EOF)
    {
        for(int i = 0; i < num; ++i)
            scanf("%d", &pre_order[i]);
        for(int i = 0; i < num; ++i)
            scanf("%d", &post_order[i]);
        pair<tree_node*, int> root_tree = generate_tree(0, num - 1, 0, num - 1);
        if(root_tree.second == 1)
            printf("Yes\n");
        else
            printf("No\n");
        in_order_sequence = 0;
        in_order_traverse(root_tree.first);

        for(int i = 0; i < num; ++i)
        {
            if(i == num - 1)
                printf("%d\n", in_order[i]);
            else
                printf("%d ", in_order[i]);
        }
    }
    return 0;
}
