#include  <iostream>
#include  <string>
#include  <algorithm>
using namespace std;

int main()
{
	string str;
	getline(std::cin,str);
	reverse(str.begin(),str.end());
	cout<<str<<endl;
}