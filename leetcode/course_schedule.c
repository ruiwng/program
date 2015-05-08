#include  <stdlib.h>
#include  <string.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesRowSize, int prerequisitesColSize) {
        char *adjacent_matrix=(char*)malloc(numCourses*numCourses*sizeof(char));
        int *precede_count=(int*)malloc(numCourses*sizeof(int));
        memset(adjacent_matrix,0,numCourses*numCourses*sizeof(char));
        memset(precede_count,0,numCourses*sizeof(int));
        for(int i=0;i<prerequisitesRowSize;++i)
        {
            int index=prerequisites[i][0]*numCourses+prerequisites[i][1];
            if(adjacent_matrix[index]==0)
            {
                adjacent_matrix[index]=1;
                ++precede_count[prerequisites[i][1]];
            }
        }
        int num=0;
        while(true)
        {
            int i=0;
            for(;i<numCourses;++i)
            {
                if(precede_count[i]==0)
                {
                    ++num;
                    precede_count[i]=-1;
                    char *p_start=&adjacent_matrix[i*numCourses];
                    for(int j=0;j<numCourses;++j)
                    {
                        if(p_start[j]==1)
                            --precede_count[j];
                    }
                    break;
                }
            }
            if(i==numCourses)
                break;
        }
        free(adjacent_matrix);
        free(precede_count);
        return num==numCourses;
}

int main()
{
    int prerequisites[8][2]={{5,8},{3,5},{1,9},{4,5},{0,2},{1,9},{7,8},{4,9}};
    bool result=canFinish(10,(int**)prerequisites,8,2);
    return 0;
}
