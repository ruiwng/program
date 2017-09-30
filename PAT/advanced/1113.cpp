#include <stdio.h>
#include <algorithm>
using namespace std;

int num_array[100001];

int main()
{
    int num;
    while(scanf("%d", &num) != EOF)
    {
        for(int i = 0; i < num; ++i)
            scanf("%d", &num_array[i]);
        sort(num_array, num_array + num);
        int num1 = num >> 1;
        int num2 = num - num1;
        int s1 = accumulate(num_array, num_array + num1, 0);
        int s2 = accumulate(num_array + num1, num_array + num, 0);
        printf("%d %d\n", num2 - num1, s2 - s1);
    }
    return 0;
}
