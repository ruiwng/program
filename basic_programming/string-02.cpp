#include  <string>
#include  <iostream>
using namespace std;

int main()
{
	string str1,str2;
	getline(std::cin,str1);
	getline(std::cin,str2);
	size_t pos;
	while((pos=str1.find(str2))!=string::npos)
		str1.erase(pos,str2.length());
	cout<<str1;
	return 0;
}