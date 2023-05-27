int strStr(char * haystack, char * needle){
    char* p = haystack;
    while(*p != '\0') {
        char* q = needle;
        char* k = p;
        while(*k != '\0' && *q != '\0' && *k == *q) {
            ++k;
            ++q;
        }
        if(*q == '\0') {
            break;
        }
        ++p;
    }
    return *p == '\0'? -1: (p - haystack);
}

int main() {
    int r = strStr("leetcode", "leeto");
    return 0;
}
