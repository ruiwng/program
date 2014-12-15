#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[22];
    int month;
    int day;
    int hour;
    int minute;
    char tag[10];
}record;

int n;
record *rd;
int rate[24];
int count, start;
double totalCharge;

double charge(int sday, int shour, int sminute, int eday, int ehour, int eminute)
{
    double cost = 0;
    long time = 0;

    while(sday < eday)
    {
        time += (60 - sminute);
        cost += (60 - sminute) * rate[shour];
        sminute = 0; shour ++;
        time += 60 * (24 - shour);
        while(shour < 24)
        {
            cost += 60 * rate[shour];
            shour ++;
        }
        shour = 0; sday ++;
    }
    while(shour < ehour)
    {
        time += (60 - sminute);
        cost += (60 - sminute) * rate[shour];
        sminute = 0; shour ++;
    }
    time += (eminute - sminute);
    cost += rate[ehour] * (eminute - sminute);

    printf("%ld $%.2lf\n", time, cost / 100);

    return cost / 100;
}

void totalCount()
{
    int i;
    for(i = start + 1; i < n; i ++)
    {
        if(strcmp(rd[i].name, rd[i - 1].name) != 0)
        {
            break;
        }
        else
        {
            count ++;
        }
    }
}

int comp_name(const void *a, const void *b)
{
    record c = *(record *)a;
    record d = *(record *)b;


    if(strcmp(c.name, d.name) <= 0) return -1;
    else return 1;
}

int comp_time(const void *a, const void *b)
{
    record c = *(record *)a;
    record d = *(record *)b;

    if(c.day < d.day) return -1;
    else if(c.day > d.day) return 1;
    else
    {
        if(c.hour < d.hour) return -1;
        else if(c.hour > d.hour) return 1;
        else
        {
            if(c.minute < d.minute) return -1;
            else return 1;
        }
    }
}

int main()
{
    int i;
    int flag;
    int onpos;
    int sign;
    

    while(scanf("%d", &rate[0]) != EOF)
    {
        for(i = 1; i < 24; i ++)
        {
            scanf("%d", &rate[i]);
        }
        scanf("%d", &n);
        rd = (record *)malloc(n * sizeof(record));
        for(i = 0; i < n; i ++)
        {
            scanf("\n%s %d:%d:%d:%d %s", rd[i].name, &rd[i].month, &rd[i].day, &rd[i].hour, &rd[i].minute, rd[i].tag);
        }
        qsort(rd, n, sizeof(record), comp_name);
        count = 1; start = 0; totalCount(); sign = 0;
        while(start < n)
        {
            qsort(rd + start, count, sizeof(record), comp_time);
            flag = 0;
            totalCharge = 0;
            for(i = start; i < start + count; i ++)
            {
                if(flag == 0)
                {
                    if(rd[i].tag[1] == 'f')
                    {
                        continue;
                    }
                    else
                    {
                        onpos = i;
                        flag = 1;
                    }
                }
                else
                {
                    if(rd[i].tag[1] == 'n')
                    {
                        onpos = i;
                    }
                    else
                    {
                        if(sign == 0)
                        {
                            printf("%s %02d\n", rd[start].name, rd[start].month);
                            sign = 1;
                        }
                        printf("%02d:%02d:%02d %02d:%02d:%02d ", rd[onpos].day, rd[onpos].hour, rd[onpos].minute, rd[i].day, rd[i].hour, rd[i].minute);
                        totalCharge += charge(rd[onpos].day, rd[onpos].hour, rd[onpos].minute, rd[i].day, rd[i].hour, rd[i].minute);
                        flag = 0;
                    }
                }
            }
            if(sign == 1)
            {
                printf("Total amount: $%.2lf\n", totalCharge);
            }
            start += count; count = 1; totalCount(); sign = 0;
        }
    }
    return 0;
}