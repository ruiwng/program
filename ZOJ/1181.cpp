#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <algorithm>
#include  <string>
using namespace std;

int main()
{
    vector<string> dictionary;
    char str[10];
    while(scanf("%s",str)!=EOF){
        if(strcmp(str,"XXXXXX")==0)
            break;
        dictionary.push_back(str);
    }
    sort(dictionary.begin(),dictionary.end());
    char scramble[10];
    while(scanf("%s",scramble)!=EOF)
    {
        if(strcmp(scramble,"XXXXXX")==0)
            break;
        int len=strlen(scramble);
        sort(scramble,scramble+len);
        bool exist=false;
        do
        {
            vector<string>::iterator iter=lower_bound(dictionary.begin(),dictionary.end(),scramble);
            if(iter!=dictionary.end()&&*iter==scramble)
            {
                printf("%s\n",scramble);
                exist=true;
            }
        }while(next_permutation(scramble,scramble+len));
        if(!exist)
            printf("NOT A VALID WORD\n");
        printf("******\n");
    }
}
