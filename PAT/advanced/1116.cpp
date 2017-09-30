#include  <stdio.h>
#include  <string.h>

#define NUM_COUNT 10001

int record[NUM_COUNT];

char prime_tag[NUM_COUNT];


int main()
{
    int num;
    memset(record, 0, sizeof(record));
    for(int i = 0; i < NUM_COUNT; ++i)
    {
        if(i == 0 || i == 1)
        {
            prime_tag[i] = 1;
            continue;
        }
        if(prime_tag[i] == 0)
        {
            int current_value = i << 1;
            while(current_value < NUM_COUNT)
            {
                prime_tag[current_value] = 1;
                current_value += i;
            }
        }
    }

    while(scanf("%d", &num) != EOF)
    {
        for(int i = 0; i < num; ++i)
        {
            int id;
            scanf("%d", &id);
            record[id] = i + 1;
        }
        scanf("%d", &num);
        for(int i = 0; i < num; ++i)
        {
            int id;
            scanf("%d", &id);
            if(record[id] == 0)
                printf("%04d: Are you kidding?\n", id);
            else if(record[id] == -1)
                printf("%04d: Checked\n", id);
            else if(record[id] == 1)
            {
                printf("%04d: Mystery Award\n", id);
                record[id] = -1;
            }
            else if(prime_tag[record[id]] == 0)
            {
                printf("%04d: Minion\n", id);
                record[id] = -1;
            }
            else
            {
                printf("%04d: Chocolate\n", id);
                record[id] = -1;
            }
        }
    }
    return 0;
}
