#include <string.h>

int lengthOfLastWord(char * s){
    char* p = s + strlen(s) - 1;
    while(p >= s && *p == ' ') {
        --p;
    }
    if(p < s) {
        return 0;
    }
    char* q = p;
    while(q >= s && *q != ' ') {
        --q;
    }
    return static_cast<int>(p - q);
}

int main() {
    int r = lengthOfLastWord("  ");
    return 0;
}
