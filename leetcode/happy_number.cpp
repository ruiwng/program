#include  <stdlib.h>
#include  <unordered_set>
using namespace std;

int power_two[]={0,1,4,9,16,25,36,49,64,81};

class Solution {
public:
    bool isHappy(int n) {
        while(n!=1)
		{
			if(traversed.find(n)!=traversed.end())
				return false;
			traversed.insert(n);
			int temp=0;
			while(n!=0)
			{
				temp+=power_two[n%10];
				n/=10;
			}
			n=temp;
		}
		return true;
    }
private:
	unordered_set<int> traversed;
};

int main()
{
	
}