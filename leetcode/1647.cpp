#include <string>
#include <unordered_set>
using namespace std;

#define CHAR_COUNT 26
class Solution {
public:
    int minDeletions(string s) {
        int char_frequency[CHAR_COUNT];
        memset(char_frequency, 0, sizeof(char_frequency));
        for(int i = 0; i < s.length(); ++i) {
            ++char_frequency[s[i] - 'a'];
        }
        
        int total_delete_count = 0;
        unordered_set<int> frequence_set;
        for(int i = 0; i < CHAR_COUNT; ++i) {
            int f = char_frequency[i];
            while(frequence_set.find(f) != frequence_set.end()) {
                --f;
                ++total_delete_count;
            }
            if(f != 0) {
                frequence_set.insert(f);
            }
        }
        
        return total_delete_count;
    }
};

int main() {
    Solution s;
    string str("ceabaacb");
    int r = s.minDeletions(str);
    return 0;
}
