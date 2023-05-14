#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& lhs, const string& rhs) -> bool {
            return lhs.length() < rhs.length();
        });
        
        auto words_count = static_cast<int>(words.size());
        vector<unsigned int> tags(words_count, 0);
        vector<unsigned int> words_length(words_count, 0);
        for(auto i = 0; i < words_count; ++i) {
            auto str_len = static_cast<unsigned int>(words[i].length());
            words_length[i] = str_len;
            for(auto j = 0; j < str_len; ++j) {
                tags[i] |= 1 << static_cast<int>(words[i][j] - 'a');
            }
        }
        
        int max_value = 0;
        for(auto j = words_count - 1; j >= 1; --j) {
            if(words_length[j] * words_length[j - 1] <= max_value) {
                break;
            }
            for(auto k = j - 1; k >= 0; --k) {
                if((tags[j] & tags[k]) == 0) {
                    auto length_product = words_length[j] * words_length[k];
                    if(length_product > max_value) {
                        max_value = length_product;
                    }
                    break;
                }
            }
        }
        return max_value;
    }
};

int main() {
    vector<string> words({"a","aa","aaa","aaaa"});
    Solution s;
    auto r = s.maxProduct(words);
    return 0;
}
