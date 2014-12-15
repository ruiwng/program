#include  <stdio.h>
#include  <string.h>
#include  <string>
#include  <vector>
#include  <unordered_map>
using namespace std;

#define    MAX_DISTANCE      1000000000

unsigned int distance_info[201][201];

struct node_info
{
    string name;
    unsigned int parent;
    unsigned int distance;
    unsigned int happiness;
    unsigned int city_count;
    unsigned int path_count;
    bool visit;
    node_info():name(),parent(0),distance(MAX_DISTANCE),happiness(0),city_count(0),path_count(0),visit(false){
    
    }
};

void print_path(vector<node_info>& info,unsigned int end)
{
    if(end!=0)
    {
       print_path(info,info[end].parent);
       printf("->");  
    }
    printf("%s",info[end].name.c_str());
}

int main()
{
    unsigned int N,K;
    char start[4];
    while(scanf("%u %u %s",&N,&K,start)!=EOF)
    {
        memset(distance_info,'\0',sizeof(distance_info));
        unordered_map<string,unsigned int> index_info;
        index_info[start]=0;
        vector<unsigned int> happiness(N);
        vector<node_info> node_array(N);
        node_array[0].name=start;
        unsigned int dest;
        for(unsigned int i=1;i<N;++i)
        {
            char pos[4];
            scanf("%s %u",pos,&happiness[i]);
            index_info[pos]=i;
            node_array[i].name=pos;
            if(strcmp(pos,"ROM")==0)
                dest=i;
        }
        for(unsigned int i=0;i<K;++i)
        {
            char begin[4],end[4];
            unsigned int dist;
            scanf("%s %s %u",begin,end,&dist);
            distance_info[index_info[begin]][index_info[end]]=dist;
            distance_info[index_info[end]][index_info[begin]]=dist;
            
        }
        node_array[0].distance=0;
        node_array[0].path_count=1;
        while(true)
        {
            unsigned int min_distance=MAX_DISTANCE;
            unsigned int current_node;
            for(unsigned int i=0;i<N;++i)
            {
                if(node_array[i].visit)
                    continue;
                if(node_array[i].distance<min_distance)
                {
                    min_distance=node_array[i].distance;
                    current_node=i;
                }
            }
            node_array[current_node].visit=true;
            if(current_node==dest)
                break;
            for(unsigned int i=0;i<N;++i)
            {
                if(node_array[i].visit||distance_info[current_node][i]==0)
                    continue;
                if(distance_info[current_node][i]+node_array[current_node].distance<node_array[i].distance)
                {
                    node_array[i].distance=distance_info[current_node][i]+node_array[current_node].distance;
                    node_array[i].happiness=node_array[current_node].happiness+happiness[i];
                    node_array[i].city_count=node_array[current_node].city_count+1;
                    node_array[i].parent=current_node;
                    node_array[i].path_count=node_array[current_node].path_count;
                }
                else if(distance_info[current_node][i]+node_array[current_node].distance==node_array[i].distance)
                {
                    node_array[i].path_count+=node_array[current_node].path_count;
                    if((node_array[current_node].happiness+happiness[i]>node_array[i].happiness)||
                    (node_array[current_node].happiness+happiness[i]==node_array[i].happiness&&
                     node_array[current_node].city_count+1<node_array[i].city_count))
                        {
                             node_array[i].parent=current_node;
                             node_array[i].happiness=node_array[current_node].happiness+happiness[i];
                             node_array[i].city_count=node_array[current_node].city_count+1;
                        }             
                }              
            }
        }
        printf("%u %u %u %u\n",node_array[dest].path_count,node_array[dest].distance,
               node_array[dest].happiness,node_array[dest].happiness/node_array[dest].city_count);
        print_path(node_array,dest);
        printf("\n");
    }
    return 0;
}
