#include <vector>
#include <string>
using namespace std;

struct Anagram {
    string str;
    unsigned int hash_value[26];
    
    bool operator < (const Anagram& ana) const {
        for(int i = 0; i < 26; ++i) {
            if(hash_value[i] != ana.hash_value[i]) {
                return hash_value[i] < ana.hash_value[i];
            }
        }
        return true;
    }
    
    bool operator != (const Anagram& ana) const {
        for(int i = 0; i < 26; ++i) {
            if(hash_value[i] != ana.hash_value[i]) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.empty()) {
            return result;
        }
        vector<Anagram> anagram_array;
        for(auto i = 0; i < strs.size(); ++i) {
            Anagram anagram;
            anagram.str = strs[i];
            memset(anagram.hash_value, 0, sizeof(unsigned int) * 26);
            for(auto j = 0; j < strs[i].length(); ++j) {
                ++anagram.hash_value[strs[i][j] - 'a'];
            }
            anagram_array.push_back(anagram);
        }
        
        sort(anagram_array.begin(), anagram_array.end());
        
        vector<string> current_anagram;
        current_anagram.push_back(anagram_array[0].str);
        for(auto i = 1; i < anagram_array.size(); ++i) {
            if(anagram_array[i] != anagram_array[i - 1]) {
                result.push_back(current_anagram);
                current_anagram.clear();
            }
            current_anagram.push_back(anagram_array[i].str);
        }
        if(!current_anagram.empty()) {
            result.push_back(current_anagram);
        }
        if(result.empty()) {
            result.push_back(vector<string>());
        }
        return result;
    }
};

int main() {
    vector<string> strs({"eat","tea","tan","ate","nat","bat"});
    Solution s;
    auto r = s.groupAnagrams(strs);
    return 0;
}
