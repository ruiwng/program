#include  <stdio.h>
#include  <string.h>
#include  <set>
using namespace std;

int arry[10010];

int find_set(int index)
{
    if(arry[index] == 0)
        return index;
    else
        arry[index] = find_set(arry[index]);
        return arry[index];
}

void merge_set(int index1, int index2)
{
    int parent1 = find_set(index1);
    int parent2 = find_set(index2);
    arry[parent2] = parent1;
}

int main()
{
    int num;
    while(scanf("%d", &num) != EOF)
    {
        memset(arry, 0, sizeof(arry));
        set<int> index_set;
        for(int i = 0; i < num; ++i)
        {
            int k;
            scanf("%d", &k);
            int start = 0;
            for(int j = 0; j < k; ++j)
            {
                int index;
                scanf("%d", &index);
                if(j == 0)
                    start = index;
                else
                    merge_set(start, index);
                index_set.insert(index);
            }
        }
        int tree_num = 0;
        for(set<int>::iterator iter = index_set.begin(); iter != index_set.end(); ++iter)
        {
            if(arry[*iter] == 0)
                ++tree_num;
        }
        printf("%d %d\n", tree_num, index_set.size());

        int query_num;
        scanf("%d", &query_num);
        for(int i = 0; i < query_num; ++i)
        {
            int index1, index2;
            scanf("%d %d", &index1, &index2);
            int parent1 = find_set(index1);
            int parent2 = find_set(index2);
            if(parent1 == parent2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
