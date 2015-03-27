int search(int A[], int n, int target) {
     int low_bound=0;
        int high_bound=n-1;
        int median;
        while(low_bound<=high_bound)
        {
            median=(low_bound+high_bound)/2;
            if(A[median]>=A[low_bound])
            {
                if(target>A[median])
                  low_bound=median+1;
                else if(target<A[median]&&target>=A[low_bound])
                  high_bound=median-1;
                else if(target<A[median]&&target<A[low_bound])
                  low_bound=median+1;
                else if(target==A[median])
                  return median;
            }
            else if(A[median]<A[low_bound])
            {
                if(target<A[median])
                  high_bound=median-1;
                else if(target>A[median]&&target<A[low_bound])
                  low_bound=median+1;
                else if(target>A[median]&&target>=A[low_bound])
                  high_bound=median-1;
                else if(target==A[median])
                  return median;
            }
        }
        return -1;
}

int main()
{
	
}