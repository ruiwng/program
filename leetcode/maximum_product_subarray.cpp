/*#include  <stdio.h>

class Solution {
public:
    int maxProduct(int A[], int n) {
       
		int index=0;
		int max_product=A[0];
		while(true)
		{
			int nega_start=-1;
			int nega_end;
			int current_product=1;
			int start=index;//the start of current part of the array.
			bool flag=false;//tag whether there exist non-zero element
			while(index<n&&A[index]!=0)//the array is divided by 0 element, get the maximum product of every part respectively. 
			{
				flag=true;
				if(A[index]<0)
				{
					if(nega_start==-1)
					    nega_start=index;
				    nega_end=index;
				}
				current_product*=A[index++];
			}
			if(index<n&&max_product<0)
				max_product=0;
			int end=index-1;//the end of current part of the array.
			if(flag)//only if there exists non-zero element can we get the maximum product of current part
			{
				if(current_product>0)//if current_product is positive, then it's the maximum.
			    {
				   if(current_product>max_product)
					   max_product=current_product;
			    }
				else
				{
					int temp=current_product;
					//fget rid of the left-most negative element
					if(nega_start!=end)
					{
						while(true)
					   {
						  temp/=A[nega_start];
						  if(start==nega_start)
							break;
						  --nega_start;
					   }
					}
					if(temp>max_product)
						max_product=temp;
					temp=current_product;
					//get rid of the right-most negative element
					if(nega_end!=start)
					{
						while(true)
					    {
						   temp/=A[nega_end];
						   if(end==nega_end)
							break;
						   ++nega_end;
					    }
					}				    
					if(temp>max_product)
						max_product=temp;
				}
			}
			if(++index>=n)
				break;
		}
		return max_product;
    }
};

int main()
{
	int A[]={3,2,-2,1};
	Solution s;
	int result=s.maxProduct(A,4);
	return 0;
}
*/

#include  <stdio.h>

class Solution {
public:
    int maxProduct(int A[], int n) {
       
		int index=0;
		int max_product=A[0];
		while(true)
		{
			int nega_start=-1;
			int nega_end;
			int current_product=1;
			int start=index;//the start of current part of the array.
			bool flag=false;//tag whether there exist non-zero element
			int left_product=0;
			int right_product=0;
			while(index<n&&A[index]!=0)//the array is divided by 0 element, get the maximum product of every part respectively. 
			{
				flag=true;
				current_product*=A[index];
				if(A[index]<0)
				{
					if(nega_start==-1)
					{
						nega_start=index;
					    left_product=current_product;
					}
				    nega_end=index;
					right_product=current_product/A[index];
				}
				++index;
			}
			if(index<n&&max_product<0)
				max_product=0;
			if(flag)//only if there exists non-zero element can we get the maximum product of current part
			{
				if(current_product>0)//if current_product is positive, then it's the maximum.
				{
					if(current_product>max_product)
						max_product=current_product;
				}
				else
				{
					if(nega_start!=index-1)//get rid of the left-most negative element
					{
						int temp=current_product/left_product;
						if(temp>max_product)
							max_product=temp;
					}
					if(nega_end!=start)//get rid of the right-most negative element
					{
						if(max_product<right_product)
							max_product=right_product;
					}
				}
			}
			if(++index>=n)
				break;
		}
		return max_product;
    }
};

int main()
{
	int A[]={3,2,-2,1};
	Solution s;
	int result=s.maxProduct(A,4);
	return 0;
}