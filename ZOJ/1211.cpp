#include  <stdio.h>
#include  <string.h>
#include  <vector>
#include  <string>
#include  <set>
using namespace std;

struct sub_dir;

struct tree_node
{
    string name;
    tree_node* parent;
    set<sub_dir> subdirectory;
    tree_node(const string& n="",tree_node* p=NULL):name(n),parent(p){
        
    }
};

struct sub_dir
{
    string name;
    tree_node* directory;
    sub_dir(const string& s="",tree_node* d=NULL):name(s),directory(d){
        
    }
    bool operator<(const sub_dir& s) const
    {
        return this->name<s.name;
    }
};

int main()
{
    printf("Problem 5 by team x\n");
    tree_node* root=new tree_node("root");
    char str[200];
    tree_node* current_directory=root;
    while(fgets(str,200,stdin)!=NULL)
    {
        if(str[strlen(str)-1]=='\n')
            str[strlen(str)-1]='\0';
        char* p=str;
        while(*p==' ')
            ++p;
        if(strncmp(p,"dir",3)==0)
        {
            printf("Command: dir\n");
            printf("Directory of %s:\n",current_directory->name.c_str());
            if(current_directory->subdirectory.empty())
                printf("No subdirectories\n");
            else
            {
                const set<sub_dir>& ref=current_directory->subdirectory;
                int k=0;
                int len=ref.size();
                for(set<sub_dir>::const_iterator iter=ref.begin();iter!=ref.end();++iter)
                {
                    ++k;
                    if(k%10==0||k==len)
                        printf("%s\n",iter->name.c_str());                   
                    else
                       printf("%-8s",iter->name.c_str());
                }
            }
         }
        else if(strncmp(p,"mkdir",5)==0)
        {
            p=strchr(p,' ');
            while(*p==' ')
                ++p;
            char temp[100];
            sscanf(p,"%s",temp);
            printf("Command: mkdir   %s\n",temp);
            set<sub_dir>& ref=current_directory->subdirectory;
            if(ref.find(sub_dir(temp))!=ref.end())
                printf("Subdirectory already exists\n");
            else
            {
                string sub_name=current_directory->name+"\\"+temp;
                tree_node* subdir=new tree_node(sub_name,current_directory);
                ref.insert(sub_dir(temp,subdir));
            }
        }
        else if(strncmp(p,"cd",2)==0)
        {
            p=strchr(p,' ');
            while(*p==' ')
                ++p;
            char temp[100];
            sscanf(p,"%s",temp);
            printf("Command: cd      %s\n",temp);
            const set<sub_dir>& ref=current_directory->subdirectory;
            set<sub_dir>::const_iterator iter=ref.find(sub_dir(temp));
            if(iter==ref.end())
                printf("Subdirectory does not exist\n");
            else
                current_directory=iter->directory;
        }
        else if(strncmp(p,"up",2)==0)
        {
            printf("Command: up\n");
            if(current_directory->parent==NULL)
                printf("Cannot move up from root directory\n");
            else
                current_directory=current_directory->parent;
        }
        else
            return -1;
    }
    printf("End of problem 5 by team x\n");
    return 0;
}
