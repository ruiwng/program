#include  <stdio.h>
#include  <string.h>

int main()
{
  char str[1010];
  while(fgets(str, 1010, stdin) != NULL)
  {
    char *p = str;
    int record[26];
    memset(record, 0, sizeof(record));

    int max_value = 0;
    char max_char;
    while(*p != '\n')
    {
      if(*p >= 'A' && *p <= 'Z')
        *p = *p - 'A' + 'a';
      if(*p >= 'a' && *p <= 'z')
      {
        if(++record[*p - 'a'] > max_value || (record[*p - 'a'] == max_value && *p < max_char))
        {
          max_value = record[*p - 'a'];
          max_char = *p;
        }
      }
      ++p;
    }

    printf("%c %d\n", max_char, max_value);
  }
  return 0;
}