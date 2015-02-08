#include  <stdio.h>

int main()
{
  int n;
  int file_number=0;
  while(scanf("%d",&n)!=EOF&&n!=0)
  {
    n=((n+1)/2+1)/2*3;
    int temp=62*30000;
    printf("File #%d\nJohn needs %d floppies.\n\n",++file_number,n%temp==0?n/temp:n/temp+1);
    
  }
  return 0;
}
