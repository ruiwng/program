#include  <string.h>

bool isAnagram(char* s, char* t) {
	 int temp[26];
	 memset(temp, 0, sizeof(temp));
	 char *p = s;
	 while(*p != '\0')
		 ++temp[*p++ - 'a'];
	 p = t;
	 while(*p != '\0')
		 --temp[*p++ - 'a'];
	 for(int i = 0; i < 26; ++i)
		 if(temp[i] != 0)
			 return false;
	 return true;
}

int main()
{
	bool result = isAnagram("anagram", "nagaram");
	result = isAnagram("rat", "car");

	return 0;
}