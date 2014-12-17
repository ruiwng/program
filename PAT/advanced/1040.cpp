#include  <stdio.h>
#include  <string.h>

int main()
{
	char ch[1010];
	while(fgets(ch,1010,stdin))
	{
		unsigned int str_len=strlen(ch);
		unsigned int longest=0;
		for(int i=0;i<str_len;i++)
		{
			int j=1;
			unsigned int current_longest=1;
			unsigned int another_longest=0;
			while(i-j>=0&&i+j<str_len)
			{
				if(ch[i-j]==ch[i+j])
				{
					current_longest+=2;
					j++;
				}
				else
				   break;
			}
			if(current_longest>longest)
				longest=current_longest;
			j=0;
			while(i-j>=0&&i+1+j<str_len)
			{
				if(ch[i-j]==ch[i+1+j])
				{
					another_longest+=2;
					j++;
				}
				else
					break;
			}
			if(another_longest>longest)
				longest=another_longest;
		}
		printf("%u\n",longest);
	}
	return 0;
}