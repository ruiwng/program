#include <string>
#include <unordered_set>
#include <stdio.h>
using namespace std;

#define CHAR_COUNT   26
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string char_map[CHAR_COUNT];
        
        int pattern_index = 0;
        int start = 0;
        int end = 0;
        unordered_set<string> mapped_str;
        
        while(true) {
            while(start < s.length() && s[start] == ' ') {
                ++start;
            }
            if(start == s.length()) {
                break;
            }
            end = start;
            while(end < s.length() && s[end] != ' ') {
                ++end;
            }
            string str = s.substr(start, end - start);
            // printf("%s\n", str.c_str());
            int char_map_pos = pattern[pattern_index] - 'a';
            if(char_map[char_map_pos] == "") {
                if(mapped_str.find(str) != mapped_str.end()) {
                    break;
                }
                mapped_str.insert(str);
                char_map[char_map_pos] = str;
            } else if(char_map[char_map_pos] != str) {
                break;
            }
            
            start = end;
            if(++pattern_index == pattern.length()) {
                break;
            }
        }
        if(pattern_index != pattern.length()) {
            return false;
        }
        while(start < s.length() && s[start] == ' ') {
            ++start;
        }
        return start == s.length();
    }
};

int main() {
    Solution s;
    string pattern("abba");
    string str("dog dog dog dog");
    bool r = s.wordPattern(pattern, str);
    return 0;
}
