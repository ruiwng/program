class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int* pIndex1=A,*pIndex2=B;
        int *pIndex3=NULL,*pIndex4=NULL;
        int temp=-1;
        if(pIndex1!=NULL&&pIndex2!=NULL)
        {
        while(pIndex1<A+m&&pIndex2<B+n&&temp!=(m+n-1)/2)
        {
            if(*pIndex1<=*pIndex2)
              pIndex3=pIndex1++;
            else
              pIndex3=pIndex2++;
            ++temp;
        }
        if(temp==(m+n-1)/2)
        {
           if(pIndex1<A+m&&pIndex2<B+n)
           {
             if(*pIndex1<=*pIndex2)
                pIndex4=pIndex1;
             else
                pIndex4=pIndex2;
           }
           else if(pIndex1==A+m&&pIndex2<B+n)
              pIndex4=pIndex2;
           else if(pIndex1!=A+m&&pIndex2==B+n)
              pIndex4=pIndex1;
        }
        }
        if(pIndex1!=NULL&&pIndex1<A+m&&(pIndex3==NULL||temp!=(m+n-1)/2))
        {
           pIndex3=pIndex1+(m+n-1)/2-1-temp;
           pIndex4=pIndex3+1;
        }
        if(pIndex2!=NULL&&pIndex2<B+n&&(pIndex3==NULL||temp!=(m+n-1)/2))
        {
           pIndex3=pIndex2+(m+n-1)/2-1-temp;
           pIndex4=pIndex3+1;
        }
        if((m+n)%2==1)
           return static_cast<double>(*pIndex3);
        else
           return static_cast<double>(*pIndex3+*pIndex4)/2;
    }
};

int main()
{
	
}