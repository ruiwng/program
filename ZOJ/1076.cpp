#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

struct gene
{
    int start;
    int end;
    int length;
    int prev_index;
    gene(int s=0,int e=0):start(s),end(e),length(1),prev_index(-1){
        
    }
    bool operator<(const gene& g) const
    {
        if(this->start!=g.start)
            return this->start<g.start;
        return this->end<g.end;
    }
};

struct comp_func
{
    bool operator()(const gene* lhs,const gene* rhs) const
    {
        return *lhs<*rhs;
    }
};
vector<gene> gene_array;
bool first;
void print_chain(int index)
{
    if(index==-1)
        return;
    print_chain(gene_array[index].prev_index);
    if(first)
        first=false;
    else
        printf(" ");
    printf("%d",index+1);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        gene_array.clear();
        gene_array.reserve(n);
        vector<gene*> gene_pointers;
        gene_pointers.reserve(n);
        for(int i=0;i<n;++i)
        {
            gene gene_temp;
            scanf("%d%d",&gene_temp.start,&gene_temp.end);
            gene_array.push_back(gene_temp);
            gene_pointers.push_back(&gene_array[i]);
        }
        sort(gene_pointers.begin(),gene_pointers.end(),comp_func());
        int longest=0;
        int longest_index=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(gene_pointers[j]->end<gene_pointers[i]->start&&gene_pointers[j]->length+1>gene_pointers[i]->length)
                {
                    gene_pointers[i]->length=gene_pointers[j]->length+1;
                    gene_pointers[i]->prev_index=gene_pointers[j]-&gene_array[0];
                    if(gene_pointers[i]->length>longest)
                    {
                        longest=gene_pointers[i]->length;
                        longest_index=gene_pointers[i]-&gene_array[0];
                    }
                }
                    
            }
        }
        first=true;
        print_chain(longest_index);
        printf("\n");
    }
    return 0;
}
