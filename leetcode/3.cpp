#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash_map[500];
        int str_length = static_cast<int>(s.length());
        memset(hash_map, 0, sizeof(int) * 500);
        int head = 0;
        int tail = 0;
        int max_length = 0;
        int current_length = 0;
        while(true) {
            while(head < str_length) {
                if(++hash_map[s[head]] == 2) {
                    break;
                }
                ++head;
                ++current_length;
            }
            if(current_length > max_length) {
                max_length = current_length;
            }
            if(head == str_length) {
                break;
            }
            while(tail < head) {
                if(--hash_map[s[tail]] == 1) {
                    ++tail;
                    break;
                }
                ++tail;
                --current_length;
            }
            ++head;
        }
        return max_length;
    }
};

int main() {
    Solution s;
    string str("bbbbb");
    int r = s.lengthOfLongestSubstring(str);
    return 0;
}
