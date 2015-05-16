#include  <stdio.h>

#define   N     100000
struct WordDictionary
{
	bool flag;
	struct WordDictionary *adjacent[26];
};

struct WordDictionary word_arry[N];
int index=0;

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate()
{
	struct WordDictionary *p=&word_arry[index++];
	p->flag=false;
	for(int i=0;i<26;++i)
		p->adjacent[i]=NULL;
	return p;
} 

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary *wordDictionary,char *word)
{
	if(*word=='\0')
		wordDictionary->flag=true;
	else
	{	if(wordDictionary->adjacent[*word-'a']==NULL)
			wordDictionary->adjacent[*word-'a']=wordDictionaryCreate();
		addWord(wordDictionary->adjacent[*word-'a'],word+1);
	}
}

/** Returns if the word is in the data structure. A word could
 * contain the dot character '.' to represent and one letter. */
bool search(struct WordDictionary *wordDictionary,char *word)
{
	if(*word=='\0')
		return wordDictionary->flag==1;
	else if(*word=='.')
	{
		for(int i=0;i<26;++i)
		{
			if(wordDictionary->adjacent[i]!=NULL&&search(wordDictionary->adjacent[i],word+1))
				return true;
		}
		return false;
	}
	else
	{
		if(wordDictionary->adjacent[*word-'a']!=NULL)
			return search(wordDictionary->adjacent[*word-'a'],word+1);
		return false;
	}
}

/** Deallocates memory previously allocated for the data structure. */
void wordDictionaryFree(struct WordDictionary *wordDictionary)
{
	index=0;
}

// Your WordDictionary object will be instantiated and called as such:
// struct WordDictionary* wordDictionary = wordDictionaryCreate();
// addWord(wordDictionary,"word");
// search(wordDictionary,"pattern");
// wordDictionaryFree(wordDictionary);

int main(){
	struct WordDictionary* wordDictionary = wordDictionaryCreate();
	addWord(wordDictionary,"word");
	bool result=search(wordDictionary,"pattern");
	printf("%s\n",result?"yes":"no");
	wordDictionaryFree(wordDictionary);
	return 0;
}
