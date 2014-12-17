
#include  <vector>
#include  <string.h>
#include  <unordered_map>
#include  <string>
#include  <algorithm>

using namespace std;

typedef struct 
{
	unsigned int number;
	char book_title[82];
	char book_author[82];
	char keywords[5][12];
	char publisher[82];
	char year[5];
}book_info;

typedef struct
{
	unsigned int query_index;
	char query_str[82];
}query_info;

struct hash_func
{
	size_t operator()(const string& str) const
	{
		size_t number=0;
		size_t len=str.length();
		for(size_t i=0;i<len;i++)
		{
			number+=str[i];
		}
		return number;
	}
};

struct equal_func
{
	bool operator()(const string& str1,const string& str2) const
	{
		return strcmp(str1.c_str(),str2.c_str())==0;
	}
};

int main()
{
	unsigned int total_books;
	while(scanf("%u",&total_books)!=EOF)
	{
		book_info book_temp;
		unordered_map<string,vector<unsigned int>,hash_func,equal_func> books_array[5];
		typedef unordered_map<string,vector<unsigned int>,hash_func,equal_func>::iterator con_iter;
		for(unsigned int i=0;i<total_books;++i)
		{
			scanf("%u",&book_temp.number);

			getchar();
			fgets(book_temp.book_title,82,stdin);
			unsigned int title_len=strlen(book_temp.book_title);
			if(book_temp.book_title[title_len-1]=='\n')
				book_temp.book_title[title_len-1]='\0';
			books_array[0][book_temp.book_title].push_back(book_temp.number);

			fgets(book_temp.book_author,82,stdin);
			unsigned int author_len=strlen(book_temp.book_author);
			if(book_temp.book_author[author_len-1]=='\n')
				book_temp.book_author[author_len-1]='\0';
			books_array[1][book_temp.book_author].push_back(book_temp.number);

			char str_temp[60];
			fgets(str_temp,60,stdin);
			unsigned int str_len=strlen(str_temp);
			if(str_temp[str_len-1]=='\n')
				str_temp[str_len-1]='\0';
			unsigned int keywords_num=sscanf(str_temp,"%s %s %s %s %s",book_temp.keywords[0],book_temp.keywords[1],book_temp.keywords[2],
				book_temp.keywords[3],book_temp.keywords[4]);
			for(unsigned int j=0;j<keywords_num;++j)
				books_array[2][book_temp.keywords[j]].push_back(book_temp.number);

			fgets(book_temp.publisher,82,stdin);
			unsigned int publisher_len=strlen(book_temp.publisher);
			if(book_temp.publisher[publisher_len-1]=='\n')
				book_temp.publisher[publisher_len-1]='\0';
			books_array[3][book_temp.publisher].push_back(book_temp.number);

			scanf("%s",book_temp.year);
			books_array[4][book_temp.year].push_back(book_temp.number);
		}
		unsigned int query_number;
		scanf("%u",&query_number);
		vector<query_info> query_array(query_number);
		for(unsigned int i=0;i<query_number;++i)
		{
			query_info query_temp;
			scanf("%u: ",&query_temp.query_index);
			fgets(query_temp.query_str,82,stdin);
			unsigned int str_len=strlen(query_temp.query_str);
			if(query_temp.query_str[str_len-1]=='\n')
				query_temp.query_str[str_len-1]='\0';
			query_array[i]=query_temp;
		}

		for(unsigned int i=0;i<query_number;++i)
		{
			query_info& query_temp=query_array[i];
			printf("%u: %s\n",query_temp.query_index,query_temp.query_str);

			con_iter iter=books_array[query_temp.query_index-1].find(query_temp.query_str);
			if(iter==books_array[query_temp.query_index-1].end())
				printf("Not Found\n");
			else
			{
				vector<unsigned int>& number_temp(iter->second);
				sort(number_temp.begin(),number_temp.end());
				for(unsigned j=0;j<number_temp.size();j++)
					printf("%07u\n",number_temp[j]);
			}
		}
	}
	return 0;
}


