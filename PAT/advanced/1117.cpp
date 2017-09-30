#include  <stdio.h>
#include  <algorithm>
#include  <functional>
using namespace std;

int main()
{
    int num;
    while(scanf("%d", &num) != EOF)
    {
        vector<int> num_array(num);
        for(int i = 0; i < num; ++i)
        {
            int distance;
            scanf("%d", &distance);
            num_array.push_back(distance);
        }
        sort(num_array.begin(), num_array.end(), greater<int>());

        int len = num_array.size();
        int max_index = 0;
        while(max_index < len && num_array[max_index] > max_index + 1)
            max_index += 1;

        printf("%d\n", max_index);
    }
    return 0;
}
