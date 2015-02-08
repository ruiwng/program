#include  <stdio.h>
#include  <vector>
using namespace std;

int time_info[100][100];
const int MAX_TIME=0x07ffffff;
int main()
{
  int input_number;
  while(scanf("%d",&input_number)!=EOF)
  {
    for(int k=0;k<input_number;++k)
    {
	int n;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
	  time_info[i][i]=0;
        for(int i=1;i<n;++i)
        {
           for(int j=0;j<i;++j)
           {
	     char str[20];
	     scanf("%s",str);
	     if(str[0]!='x')
	       sscanf(str,"%d",&time_info[i][j]);
	     else
	       time_info[i][j]=MAX_TIME;
	      time_info[j][i]=time_info[i][j];
           }
        }
        vector<int> time_array(n,MAX_TIME);
        time_array[0]=0;
        int index=0;
        while(true)
        {
           int current_time=MAX_TIME;
           int current_index;
           for(int i=0;i<n;++i)
           {
	     if(time_array[i]!=-1&&time_array[i]<current_time)
             {
	        current_time=time_array[i];
	        current_index=i;
             }
           }
           if(++index==n)
           {
	     printf("%s%d\n",k!=0?"\n":"",current_time);
              break;
           }
          for(int i=0;i<n;++i)
          {
	    if(time_array[i]==-1)
	       continue;
	    if(time_array[current_index]+time_info[current_index][i]<time_array[i])
	       time_array[i] = time_array[current_index]+time_info[current_index][i];
          }
	  time_array[current_index]=-1;
       }
    }
  }
  return 0;
}
