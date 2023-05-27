#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int str_len = static_cast<int>(s.length());
        int word_len = static_cast<int>(words[0].length());
        int word_count = static_cast<int>(words.size());
        int concatenated_word_len = word_len * word_count;
        unordered_map<string, int> word_dict;
        for(int i = 0; i < words.size(); ++i) {
            auto iter = word_dict.find(words[i]);
            if(iter == word_dict.end()) {
                word_dict.insert({words[i], 1});
            } else {
                ++iter->second;
            }
        }
        
        vector<int> results;
        unordered_set<int> jump_set;
        for(int i = 0; i <= str_len - concatenated_word_len; ++i) {
            if(jump_set.find(i) != jump_set.end()) {
                continue;
            }
            int start = i;
            unordered_map<string, int> local_word_dict;
            while(true) {
                string str = s.substr(start, word_len);
                auto iter = word_dict.find(str);
                auto iter2 = local_word_dict.find(str);
                if(iter == word_dict.end() || (iter2 != local_word_dict.end() && iter->second == iter2->second)) {
                    if(iter2 != local_word_dict.end()) {
                        ++iter2->second;
                    }
                    break;
                }
                if(iter2 != local_word_dict.end()) {
                    ++iter2->second;
                } else {
                    local_word_dict.insert({str, 1});
                }
                start += word_len;
                if(start - i == concatenated_word_len) {
                    break;
                }
            }
            if(start - i == concatenated_word_len) {
                results.push_back(i);
                int j = i;
                while(s.substr(start, word_len) == s.substr(j, word_len)) {
                    results.push_back(j + word_len);
                    jump_set.insert(j + word_len);
                    start += word_len;
                    j += word_len;
                }
                j = i;
                while(j < start) {
                    auto iter = local_word_dict.find(s.substr(j, word_len));
                    if(iter != local_word_dict.end() && iter->second > 1) {
                        break;
                    }
                    jump_set.insert(j);
                    j += word_len;
                }
            } else {
                int j = i;
                while(j <= start) {
                    auto iter = local_word_dict.find(s.substr(j, word_len));
                    if(iter != local_word_dict.end() && iter->second > 1) {
                        break;
                    }
                    jump_set.insert(j);
                    j += word_len;
                    
                }
            }
        }
        return results;
    }
};

int main() {
    Solution s;
    string str("acccaccaa");
    vector<string> words({"aa","cc","ca"});
    vector<int> r = s.findSubstring(str, words);
    return 0;
}
