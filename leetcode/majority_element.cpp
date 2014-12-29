#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int start=0,end=num.size()-1;
        median=(start+end)>>1;
        partition(num,start,end);
        return num[median];
    }
private:
    void swap(int& a,int& b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    void insertion_sort(vector<int>& num,int start,int end)
    {
        for(int index=start+1;index<=end;++index)
        {
            int temp=num[index];
            int t=index-1;
            while(num[t]>temp&&t>=start)
            {
                num[t+1]=num[t];
                --t;
            }               
            num[t+1]=temp;
        }
    }
    void partition(vector<int>& num,int start,int end)
    {
        if(start>=end)
            return;
        if(start+2>=end)
        {
            insertion_sort(num,start,end);
            return;
        }
        int low=start;
        int high=end;
        int key=num[low];
        while(low<high)
        {
            while(low<high&&num[high]>=key)
                --high;
            num[low]=num[high];
            while(low<high&&num[low]<=key)
                ++low;
            num[high]=num[low];
        }
        num[low]=key;
        if(low<median)
            partition(num,low+1,end);
        else if(low>median)
            partition(num,start,low-1);
    }
private:
            int median;
};

int main()
{
    int arry[]={
        47,47,72,47,72,47,79,47,12,92,13,47,47,83,33,15,18,47,47,47,47,64,47,65,47,47,47,47,70,47,47,55,47,15,60,47,47,47,47,47,46,30,58,59,47,47,47,47,47,90,64,37,20,47,100,84,47,47,47,47,47,89,47,36,47,60,47,18,47,34,47,47,47,47,47,22,47,54,30,11,47,47,86,47,55,40,49,34,19,67,16,47,36,47,41,19,80,47,47,27
    };
    vector<int> test(arry,arry+sizeof(arry));
    Solution s;
    int result=s.majorityElement(test);
    printf("%d\n",result);
    
    return 0;
}
