#include  <stdio.h>
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
