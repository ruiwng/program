#include <string.h>

char * reverseWords(char * s){
    if(s == NULL) {
        return NULL;
    }
    
    char* p_start = s;
    char* p_end = p_start + strlen(s) - 1;
    while(p_start < p_end) {
        char temp = *p_start;
        *p_start = *p_end;
        *p_end = temp;
        ++p_start;
        --p_end;
    }
    
    p_start = s;
    char* p_result = s;
    bool is_first = true;
    while(true) {
        while(*p_start != '\0' && *p_start == ' ') {
            ++p_start;
        }
        if(*p_start == '\0') {
            break;
        }
        p_end = p_start;
        while(*p_end != '\0' && *p_end != ' ') {
            ++p_end;
        }
        
        char* p = p_start;
        char* q = p_end - 1;
        while(p < q) {
            char temp = *p;
            *p = *q;
            *q = temp;
            ++p;
            --q;
        }
        if(is_first) {
            is_first = false;
        } else {
            *p_result++ = ' ';
        }
        while(p_start < p_end) {
            *p_result = *p_start;
            ++p_result;
            ++p_start;
        }
        p_start = p_end;
    }
    *p_result = '\0';
    return s;
}

int main() {
    char str[] = "a good   example";
    char* res = reverseWords(str);
    return 0;
}
