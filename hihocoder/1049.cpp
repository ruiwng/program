#include  <stdio.h>
#include  <string.h>

struct tree_node
{
	char element;
	tree_node *left, *right;
	tree_node(char e, tree_node *l = NULL, tree_node *r = NULL):element(e), left(l), right(r){}
};

tree_node *generate_tree(char *pre_order, int pre_start, int pre_end,
						 char *in_order, int in_start, int in_end)
{
	if(pre_start > pre_end)
		return NULL;
	else if(pre_start == pre_end)
		return new tree_node(pre_order[pre_start]);
	else
	{
		int i = in_start;
		while(i <= in_end && in_order[i] != pre_order[pre_start])
			++i;
		int left = i - in_start;
		return new tree_node(pre_order[pre_start],
			generate_tree(pre_order, pre_start + 1, pre_start + left, in_order, in_start, in_start + left - 1),
			generate_tree(pre_order, pre_start + left + 1, pre_end, in_order, in_start + left + 1, in_end));
	}
}

void post_order(tree_node *root)
{
	if(root != NULL)
	{
		post_order(root->left);
		post_order(root->right);
		printf("%c", root->element);
	}
}
int main()
{
	char pre_order[50], in_order[50];
	while(scanf("%s%s", pre_order, in_order) != EOF)
	{
		tree_node *root = generate_tree(pre_order, 0, strlen(pre_order) - 1, 
			in_order, 0, strlen(in_order) - 1);
		post_order(root);
		printf("\n");
	}
	return 0;
}