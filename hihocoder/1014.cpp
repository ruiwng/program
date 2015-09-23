#include  <stdio.h>

struct trie
{
	int count;
	trie *children[26];
	trie():count(0)
	{
		for(int i = 0; i < 26; ++i)
			children[i] = NULL;
	}
};

void trie_insert(trie **root, const char *str)
{
	while(*str != '\0')
	{
		if((*root) == NULL)
			*root = new trie;
		++(*root)->count;
		root = &((*root)->children[*str - 'a']);
		++str;
	}
	if((*root) == NULL)
			*root = new trie;
	++(*root)->count;
}

int trie_query(trie *root, const char *str)
{
	while(*str != '\0')
	{
		if(root->children[*str - 'a'] == NULL)
			return 0;
		root = root->children[*str - 'a'];
		++str;
	}
	return root->count;
}
int main()
{
	int n, m;
	while(scanf("%d", &n) != EOF)
	{
		trie* root = NULL;
		for(int i = 0; i < n; ++i)
		{
			char str[20];
			scanf("%s", str);
			trie_insert(&root, str);
		}

		scanf("%d", &m);
		for(int i = 0; i < m; ++i)
		{
			char query[20];
			scanf("%s", query);
			printf("%d\n", trie_query(root, query));
		}
	}
	return 0;
}