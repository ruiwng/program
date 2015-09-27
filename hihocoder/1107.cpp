#include  <stdio.h>

char str[2000010];

struct trie
{
	int number;
	trie *children[26];
	trie():number(0)
	{
		for(int i = 0; i < 26; ++i)
			children[i] = NULL;
	}
};

void trie_insert(trie **root, char *s)
{
	while(true)
	{
		if(*root == NULL)
			*root = new trie;
		++(*root)->number;
		if(*s == '\0')
			break;
		root = &((*root)->children[*s - 'a']);
		++s;
	}
}

int proper;

void trie_traverse(trie *root)
{
	if(root != NULL)
	{
		if(root->number <= 5)
			++proper;
		else
		{
			for(int i = 0; i < 26; ++i)
				trie_traverse(root->children[i]);
		}
	}
}

int main()
{
	int n;
	while(scanf("%d", &n) != EOF)
	{
		trie *root = NULL;
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", str);
			trie_insert(&root, str);
		}
		proper = 0;
		trie_traverse(root);
		if(root->number <= 5)
			--proper;
		printf("%d\n", proper);
	}
	return 0;
}