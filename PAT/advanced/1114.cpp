#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int estate;
    int area;

    Node(int estate, int area):estate(estate), area(area){}
    Node(){}
};

struct Node1
{
    vector<int> neighbors;
    bool is_traversed;
    Node1(): neighbors(), is_traversed(false){}
};

struct Family
{
    int id;
    int family_num;
    float estate_average;
    float area_average;

    Family(int id, int family_num, float estate_average, float area_average): id(id), family_num(family_num), estate_average(estate_average), area_average(area_average){}

    bool operator < (const Family &f) const
    {
        if(this->area_average != f.area_average)
            return this->area_average > f.area_average;
        return this->id < f.id;
    }
};

int family_num;
int estate_total;
int area_total;
int id;

void traverse(map<int, Node> &node_array, map<int, Node1> &relatives, int key)
{
    if(relatives[key].is_traversed)
        return;
    family_num += 1;
    Node1 &m = relatives[key];
    m.is_traversed = true;
    if(key < id)
        id = key;
    if(node_array.find(key) != node_array.end())
    {
        Node &n = node_array[key];
        estate_total += n.estate;
        area_total += n.area;
    }
    for(vector<int>::iterator iter = m.neighbors.begin(); iter != m.neighbors.end(); ++iter)
        traverse(node_array, relatives, *iter);
}

int main()
{
    int num;
    while(scanf("%d", &num) != EOF)
    {
        map<int, Node> node_array;
        map<int, Node1> relatives;
        for(int i = 0; i < num; ++i)
        {
            int owner, father, mother, child_count;
            scanf("%d%d%d%d", &owner, &father, &mother, &child_count);
            if(relatives.find(owner) == relatives.end())
                relatives[owner] = Node1();
            if(father != -1)
            {
                relatives[father].neighbors.push_back(owner);
                relatives[owner].neighbors.push_back(father);
            }
            if(mother != -1)
            {
                relatives[mother].neighbors.push_back(owner);
                relatives[owner].neighbors.push_back(mother);
            }
            for(int j = 0; j < child_count; ++j)
            {
                int child;
                scanf("%d", &child);
                relatives[owner].neighbors.push_back(child);
                relatives[child].neighbors.push_back(owner);
            }
            int estate, area;
            scanf("%d%d", &estate, &area);
            node_array[owner] = Node(estate, area);
        }

        vector<Family> family_array;
        for(map<int, Node1>::iterator iter = relatives.begin(); iter != relatives.end(); ++iter)
        {
            if(iter->second.is_traversed)
                continue;
            family_num = 0;
            id = iter->first;
            estate_total = 0;
            area_total = 0;
            traverse(node_array, relatives, iter->first);
            family_array.push_back(Family(id, family_num, float(estate_total) / family_num, float(area_total) / family_num));
        }

        sort(family_array.begin(), family_array.end());
        printf("%d\n", family_array.size());
        for(vector<Family>::iterator iter = family_array.begin(); iter != family_array.end(); ++iter)
            printf("%04d %d %.3f %.3f\n", iter->id, iter->family_num, iter->estate_average, iter->area_average);
    }
    return 0;
}
