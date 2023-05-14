#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int len = static_cast<int>(chars.size());
        if(len == 0) {
            return 0;
        }
        int start = 0;
        int i = 0;
        
        while(true) {
            char k = chars[i];
            int count = 0;
            while(i < len && chars[i] == k) {
                ++count;
                ++i;
            }
            chars[start++] = k;
            if(count > 1) {
                auto str = std::to_string(count);
                for(auto m = 0; m < str.length(); ++m) {
                    chars[start++] = str[m];
                }
            }
            if(i == len) {
                break;
            }
        }
        return start;
    }
};

int main() {
    Solution s;
    vector<char> chars({'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'});
    int n = s.compress(chars);
    return 0;
}
*/
