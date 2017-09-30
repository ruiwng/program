#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <map>
#include  <set>
using namespace std;

int main()
{
    int num;
    while(scanf("%d", &num) != EOF)
    {
        map<int, int> record;
        for(int i = 0; i < num; ++i)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            record[a] = b;
            record[b] = a;
        }

        scanf("%d", &num);
        set<int> singles;
        for(int i = 0; i < num; ++i)
        {
            int a;
            scanf("%d", &a);
            singles.insert(a);
        }

        vector<int> results;
        for(set<int>::iterator iter = singles.begin(); iter != singles.end(); ++iter)
        {
            if(record.find(*iter) == record.end() || singles.find(record[*iter]) == singles.end())
                results.push_back(*iter);
        }

        int length = results.size();
        printf("%d\n", length);
        for(int i = 0; i < length; ++i)
        {
            if(i == length - 1)
                printf("%05d\n", results[i]);
            else
                printf("%05d ", results[i]);
        }
    }
    return 0;
}
