#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int repeat_times;
    char str[1010];
    char repeat_chars[300];
    while(scanf("%d%s", &repeat_times, str) != EOF)
    {
        memset(repeat_chars, 1, sizeof(repeat_chars));
        char *p = str;
        char *q;
        while(*p != '\0')
        {
            q = p + 1;
            while(*q != '\0' && q - p != repeat_times)
            {
                if(*q != *p)
                    break;
                q += 1;
            }
            if(q - p != repeat_times)
            {
                repeat_chars[*p] = 0;
            }
            p = q;
        }
        p = str;
        q = str;
        while(*p != '\0')
        {
            if(repeat_chars[*p] != 0)
            {
                if(repeat_chars[*p] == 1)
                    printf("%c", *p);
                repeat_chars[*p] = 2;
                if(p != q)
                    *q++ = *p;
                else
                    ++q;
                p += repeat_times;
            }
            else
                *q++ = *p++;
        }
        *q = '\0';
        printf("\n%s\n", str);
    }
    return 0;
}
