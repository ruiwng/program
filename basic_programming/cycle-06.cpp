#include  <iostream>
#include  <string>
using namespace std;

int main()
{
	string str;
	size_t start=0;
	while(getline(std::cin,str))
	{
		unsigned int count=0;
		while((start=str.find_first_not_of(' ',start))!=string::npos)
		{
			count++;
			start=str.find_first_of(' ',start);
		}
		printf("%u\n",count);
	}
	return 0;
}