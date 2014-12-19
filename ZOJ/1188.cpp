/*#include  <stdio.h>
#include  <string>
#include  <vector>
#include  <algorithm>
using namespace std;

struct DNA
{
    string  sequence;
    int sortedness;
    DNA(string s="",int l=0):sequence(s),sortedness(l){
        
    }
    bool operator<(const DNA& d) const
    {
        return this->sortedness<d.sortedness;
    }
};

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            if(i!=0)
                printf("\n");
            int length,number;
            scanf("%d%d",&length,&number);
            vector<DNA> DNA_array;
            DNA_array.reserve(number);
            for(int j=0;j<number;++j)
            {
                char str[60];
                scanf("%s",str);
                DNA_array.push_back(DNA(str));
            }

            for(int j=0;j<number;++j)
            {
                string temp=DNA_array[j].sequence;
                int sortedness=0;
                for(int k=0;k<length;++k)
                {
                    for(int m=k+1;m<length;++m)
                        if(temp[k]>temp[m])
                            ++sortedness;
                }
                DNA_array[j].sortedness=sortedness;
            }

            stable_sort(DNA_array.begin(),DNA_array.end());

            for(int j=0;j<number;++j)
                printf("%s\n",DNA_array[j].sequence.c_str());
        }
    }
    return 0;
}
*/
#include  <stdio.h>
#include  <string>
#include  <vector>
#include  <algorithm>
using namespace std;

struct DNA
{
    string  sequence;
    int sorted_level;
    DNA(string s="",int l=0):sequence(s),sorted_level(l){
        
    }
    bool operator<(const DNA& d) const
    {
        return this->sorted_level<d.sorted_level;
    }
};

int sorted_number;

void merge_sort(string &s,int start,int end)
{
    if(start==end)
        return;
    int median=(start+end)>>1;
    merge_sort(s,start,median);
    merge_sort(s,median+1,end);
    int j=start;
    int k=median+1;
    string temp;
    while(j<=median&&k<=end)
    {
        if(s[j]>s[k])
        {
            sorted_number+=end-k+1;
            temp.push_back(s[j]);
            ++j;
        }
        else
        {
            temp.push_back(s[k]);
            ++k;
        }
    }
    while(j<=median)
        temp.push_back(s[j++]);
    while(k<=end)
        temp.push_back(s[k++]);
    int length=end-start+1;
    for(int i=0;i<length;++i)
        s[i+start]=temp[i];
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            if(i!=0)
                printf("\n");
            int length,number;
            scanf("%d%d",&length,&number);
            vector<DNA> DNA_array;
            DNA_array.reserve(number);
            for(int j=0;j<number;++j)
            {
                char str[60];
                scanf("%s",str);
                DNA_array.push_back(DNA(str));
            }

            for(int j=0;j<number;++j)
            {
                sorted_number=0;
                string temp=DNA_array[j].sequence;
                merge_sort(temp,0,temp.size()-1);
                DNA_array[j].sorted_level=sorted_number;
            }

            stable_sort(DNA_array.begin(),DNA_array.end());

            for(int j=0;j<number;++j)
                printf("%s\n",DNA_array[j].sequence.c_str());
        }
    }
    return 0;
}


