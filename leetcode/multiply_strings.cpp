#include  <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string result;
        int length1=num1.length();
        int length2=num2.length();
        for(int i=length2-1;i>=0;--i)
        {
            int carry=0;
            string temp;
            for(int j=length1-1;j>=0;--j)
            {
                int num_temp=(num1[j]-'0')*(num2[i]-'0')+carry;
                if(num_temp>=10)
                {
                    carry=num_temp/10;
                    num_temp%=10;
                }
                else
                   carry=0;
                temp.insert(temp.begin(),num_temp+'0');
            }
            if(carry!=0)
               temp.insert(temp.begin(),carry+'0');
            temp.append(length2-1-i,'0');
            result=plus(result,temp);
        }
		while(!result.empty()&&result.front()=='0')
			result.erase(result.begin());
		if(result.empty())
			result.push_back('0');
        return result;
    }
private:
    string plus(string num1,string num2)
    {
        if(num1.size()<num2.size())
            num1.swap(num2);
        num2.insert(num2.begin(),num1.length()-num2.length(),'0');
        
        int length=num1.size();
        int carry=0;
        for(int i=length-1;i>=0;--i)
        {
            int temp=num1[i]-'0'+num2[i]-'0'+carry;
            if(temp>=10)
            {
                temp-=10;
                carry=1;
            }
            else
               carry=0;
            num1[i]=temp+'0';
        }
        if(carry!=0)
           num1.insert(num1.begin(),carry+'0');
        return num1;
    }
};

int main()
{
	
}