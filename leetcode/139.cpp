#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int max_word_length = 0;
        int min_word_length = std::numeric_limits<int>::max();
        for(int i = 0; i < wordDict.size(); ++i) {
            int len = static_cast<int>(wordDict[i].length());
            if(len > max_word_length) {
                max_word_length = len;
            }
            if(len < min_word_length) {
                min_word_length = len;
            }
        }
        unordered_set<string> word_dict(wordDict.begin(), wordDict.end());
        int str_len = static_cast<int>(s.length());
        vector<char> dp(str_len, 0);
        for(int i = min_word_length - 1; i < str_len; ++i) {
            for(int j = i - (min_word_length - 1); j >= 0 && j >= i - (max_word_length - 1); --j) {
                if(j != 0 && dp[j - 1] == 0) {
                    continue;
                }
                if(word_dict.find(s.substr(j, i + 1 - j)) == word_dict.end()){
                    continue;
                }
                dp[i] = 1;
                break;
            }
        }
        return dp[str_len - 1] == 1;
    }
};

int main() {
    Solution s;
    string str("catsandog");
    vector<string> wordDict({"cats","dog","sand","and","cat"});
    bool res = s.wordBreak(str, wordDict);
    return 0;
}
