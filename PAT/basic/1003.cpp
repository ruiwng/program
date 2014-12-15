#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <vector>
#include  <iterator>
using namespace std;

int main()

{
      int n=0;   
      char ch[101];
      while(scanf("%d",&n)!=EOF)
     {  
         vector<int> intVec;  
         for(int i=0;i<n;i++)  
         {      
            scanf("%s",ch);  
            int len=strlen(ch);  
            int j=0;  
            int cnt1=0,cnt2=0,cnt3=0;   
            for(;j<len;j++)     
            {       
               if(ch[j]=='A')     
                 cnt1++;     
               else       
                 break; 
            }        
            if(j>(len-1)||ch[j++]!='P')      
           {        
                intVec.push_back(0);         
                continue;     
            }       
           for(;j<len;j++)    
           {        
                if(ch[j]=='A')       
                  cnt2++;        
                else         
                  break;     
           }     
           if(j>(len-1)||ch[j++]!='T')     
           {        
                intVec.push_back(0);    
                continue;  
           }         
           for(;j<len;j++)   
           {     
                if(ch[j]=='A')         
                   cnt3++;        
                else        
                   break;    
           }       
           if(j!=len)  
           {        
               intVec.push_back(0);         
               continue;   
           }   
           if(cnt1==cnt3)
		   {
			   if(cnt2==1||(cnt1==0&&cnt3==0&&cnt2>=1))
				    intVec.push_back(1);  
			   else
				    intVec.push_back(0);
		   }
           else if((cnt3%cnt1)==0&&cnt2==(cnt3/cnt1))   
               intVec.push_back(1);   
           else       
               intVec.push_back(0); 
       }  
       for(vector<int>::const_iterator it=intVec.begin();it!=intVec.end();++it)
       {    
            if(*it==1)    
                 printf("YES\n");    
            else     
                 printf("NO\n");  
        } 
  }
    return 0;
}
