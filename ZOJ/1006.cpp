#include  <stdio.h>
#include  <string.h>

int ciphercode[28]=
{
	'_','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t',
    'u','v','w','x','y','z','.'
};

int main()
{
	int key;
	while(scanf("%d",&key)!=EOF&&key)
	{
		char ciphertext[80];
		char plaintext[80];
		memset(plaintext,0,sizeof(plaintext));
		scanf("%s",ciphertext);
		int length=strlen(ciphertext);

		for(int i=0;i<length;++i)
		{
			int temp;
			if(ciphertext[i]=='_')
				temp=0;
			else if(ciphertext[i]=='.')
				temp=27;
			else
				temp=ciphertext[i]-'a'+1;
			temp+=i;
			while(temp>=28)
				temp-=28;
			plaintext[(key*i)%length]=ciphercode[temp];		
		}
		printf("%s\n",plaintext);
	}
	return 0;
}