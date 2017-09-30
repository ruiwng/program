#include  <stdio.h>
#include  <set>
using namespace std;

int main()
{
    int num;
    while(scanf("%d", &num) != EOF)
    {
        set<int> friend_set;
        for(int i = 0; i < num; ++i)
        {
            char str[10];
            scanf("%s", str);
            char *p = str;
            int friends = 0;
            while(*p != '\0')
            {
                friends += (*p) - '0';
                ++p;
            }
            friend_set.insert(friends);
        }
        printf("%d\n", friend_set.size());
        for(set<int>::iterator iter = friend_set.begin(); iter != friend_set.end(); ++iter)
        {
            if(iter != friend_set.begin())
                printf(" ");
            printf("%d", *iter);
        }
        printf("\n");
    }
    return 0;
}
