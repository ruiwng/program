#include  <stdlib.h>

#define   N   26

struct TrieNode {
    int exist;
    struct TrieNode *child[N];
};

struct TrieNode node_array[100000];
int ind=0;
/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    node_array[ind].exist=0;
    for(int i=0;i<N;++i)
      node_array[ind].child[i]=NULL;
    return &node_array[ind++];
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    struct TrieNode **p=&root;
    while(true)
    {
        if(*p==NULL)
            *p=trieCreate();
        if(*word=='\0')
        {
            (*p)->exist=1;
             break;
        }
        p=&((*p)->child[*word-'a']);
        ++word;
    }
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    struct TrieNode **p=&root;
    while(true)
    {
        if(*p==NULL)
            return false;
        if(*word=='\0')
            return (*p)->exist==1;
        p=&((*p)->child[*word-'a']);
        ++word;
    }
}

/** Returns if there is any word in the trie
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    struct TrieNode **p=&root;
    while(true)
    {
        if(*p==NULL)
            return false;
        if(*prefix=='\0')
            return true;
        p=&((*p)->child[*prefix-'a']);
        ++prefix;
    }
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    ind=0;
}

int main()
{
    struct TrieNode *node=trieCreate();
    insert(node,"a");
    bool result=search(node,"a");
    result=startsWith(node,"a");
    return 0;
}
// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);
