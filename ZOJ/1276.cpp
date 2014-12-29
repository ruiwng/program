#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <string>
using namespace std;

#define   MAX_MULTI       0x7fffffff

struct matrix
{
    int row;
    int column;
    matrix(int r=0,int c=0):row(r),column(c){
        
    }
};

struct record
{
    int multi_time;
    int pos;
};

record record_array[10][10];

string generate_sequence(int start,int end)
{
    if(start==end)
    {
        char str[5];
        sprintf(str,"A%d",start+1);
        return str;
    }
    else
        return "("+generate_sequence(start,record_array[start][end].pos)+" x "+generate_sequence(record_array[start][end].pos+1,end)+")";
}

int main()
{
    int n;
    int case_number=0;
    while(scanf("%d",&n)!=EOF&&n)
    {
          vector<matrix>  matrix_array;
          matrix_array.reserve(n);
          for(int i=0;i<n;++i)
          {
              matrix m;
              scanf("%d%d",&m.row,&m.column);
              matrix_array.push_back(m);
          }
          for(int i=0;i<n;++i)
              record_array[i][i].multi_time=0;
          for(int i=1;i<n;++i)
          {
              int j=0;
              while(j+i<n)
              {
                  record_array[j][j+i].multi_time=MAX_MULTI;
                  for(int k=0;k<i;++k)
                  {
                      int temp=record_array[j][j+k].multi_time+record_array[j+k+1][j+i].multi_time+matrix_array[j].row*matrix_array[j+k].column*matrix_array[j+i].column;
                      if(temp<record_array[j][j+i].multi_time)
                      {
                          record_array[j][j+i].multi_time=temp;
                          record_array[j][j+i].pos=j+k;
                      }
                  }
                  j+=1;
              }              
          }
          string result=generate_sequence(0,n-1);
          printf("Case %d: %s\n",++case_number,result.c_str());
    }
    return 0;
}
