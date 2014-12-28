#include  <stdio.h>
#include  <set>
using namespace std;

int main()
{
    int n;
    int program_number=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
        set<char> definite_set;
        definite_set.insert('a');
        for(int i=0;i<n;++i)
        {
            char str1[3],str2[3];
            scanf("%s = %s",str1,str2);
            set<char>::iterator iter1=definite_set.find(str1[0]);
            set<char>::iterator iter2=definite_set.find(str2[0]);
            if(iter1==definite_set.end()&&iter2!=definite_set.end())
                definite_set.insert(str1[0]);
            else if(iter1!=definite_set.end()&&iter2==definite_set.end())
                definite_set.erase(iter1);
        }
        printf("Program #%d\n",++program_number);
        if(definite_set.empty())
            printf("none\n");
        else
        {
            for(set<char>::iterator iter=definite_set.begin();iter!=definite_set.end();++iter)
                printf("%c ",*iter);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
