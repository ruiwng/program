/*#include  <stdio.h>
#include  <string.h>
#include  <map>
#include  <string>
using namespace std;

int main()
{
    map<string,string> dictionary;
    char str[30];
    while(fgets(str,30,stdin)!=NULL)
    {
        if(str[0]=='\n')
            break;
        char english[20],mouse_words[20];
        sscanf(str,"%s%s",english,mouse_words);
        dictionary[mouse_words]=english;
    }

    char mouse[20];
    while(scanf("%s",mouse)!=EOF)
    {
        map<string,string>::iterator iter=dictionary.find(mouse);
        if(iter!=dictionary.end())
            printf("%s\n",iter->second.c_str());
        else
            printf("eh\n");
    }
    return 0;
}
*/

#include  <stdio.h>
#include  <string>
#include  <vector>
#include  <algorithm>
using namespace std;

struct word
{
    string mouse;
    string english;
    word(const string& m="",const string& e=""):mouse(m),english(e){
        
    }
    bool operator<(const word& w) const
    {
        return this->mouse<w.mouse;
    }
};

int main()
{
    vector<word> dictionary;
    char str[30];
    while(fgets(str,30,stdin)!=NULL)
    {
        if(str[0]=='\n')
            break;
        char english[20],mouse_words[20];
        sscanf(str,"%s%s",english,mouse_words);
        dictionary.push_back(word(mouse_words,english));  
    }

    sort(dictionary.begin(),dictionary.end());
     char mouse[20];
     while(scanf("%s",mouse)!=EOF)
     {
         vector<word>::iterator iter=lower_bound(dictionary.begin(),dictionary.end(),word(mouse));
         
         if(iter!=dictionary.end()&&iter->mouse==mouse)
             printf("%s\n",iter->english.c_str());
        else
            printf("eh\n");
     }
     return 0;
}
