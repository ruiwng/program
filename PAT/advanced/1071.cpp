#include  <iostream>
#include  <map>
#include  <string>
using namespace std;

char* array="0123456789abcdefghijklmnopqrstuvwxyz";

int main()
{
	string str;
	while(getline(std::cin,str))
	{
		map<string,int> string_array;
		size_t pos1=0,pos2=0;
		for(unsigned int i=0;i<str.size();++i)
			str[i]=tolower(str[i]);

		while(pos1!=string::npos)
		{
			pos1=str.find_first_of(array,pos1);
			pos2=str.find_first_not_of(array,pos1);
			string_array[string(str,pos1,pos2-pos1)]++;
			pos1=str.find_first_of(array,pos2);
		}
		map<string,int>::const_iterator current=string_array.begin();
		for(map<string,int>::const_iterator iter=string_array.begin();
			iter!=string_array.end();++iter)
		{
			if(iter->second>current->second)
				current=iter;
		}
		printf("%s %d\n",current->first.c_str(),current->second);
	}
	return 0;
}