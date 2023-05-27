#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int len = static_cast<int>(t.size());
        int char_record[512];
        memset(char_record, 0, sizeof(char_record));
        for(int i = 0; i < len; ++i) {
            ++char_record[t[i]];
        }
        
        vector<int> pos_record;
        for(int i = 0; i < s.length(); ++i) {
            if(char_record[s[i]] > 0) {
                pos_record.push_back(i);
            }
        }
        
        int local_char_record[512];
        memset(local_char_record, 0, sizeof(local_char_record));
        
        int start = 0;
        int end = 0;
        int current_len = 0;
        int min_start = -1;
        int min_len = numeric_limits<int>::max();
        while(true) {
            while(end < pos_record.size()) {
                char c = s[pos_record[end++]];
                if(++local_char_record[c] <= char_record[c]) {
                    ++current_len;
                    if(current_len == len) {
                        break;
                    }
                }
            }
            if(current_len != len) {
                break;
            }
            while(start < end) {
                char c = s[pos_record[start]];
                if(local_char_record[c] - 1 >= char_record[c]) {
                    --local_char_record[c];
                    ++start;
                } else {
                    break;
                }
            }
            
            // printf("%s\n", s.substr(pos_record[start], pos_record[end - 1] - pos_record[start] + 1).c_str());
            if(pos_record[end - 1] - pos_record[start] + 1 < min_len) {
                min_len = pos_record[end - 1] - pos_record[start] + 1;
                min_start = pos_record[start];
            }
            
            if(end == pos_record.size()) {
                break;
            }
            
            char c = s[pos_record[start]];
            --local_char_record[c];
            --current_len;
            ++start;
        }
        return min_start == -1 ? "": s.substr(min_start, min_len);
    }
};

int main() {
    Solution s;
    string str = "a";
    string t = "aa";
    auto r = s.minWindow(str, t);
    printf("%s\n", r.c_str());
    return 0;
}
