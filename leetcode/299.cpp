#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int secret_record[10];
        int guess_record[10];
        memset(secret_record, 0, sizeof(secret_record));
        memset(guess_record, 0, sizeof(guess_record));
        int bull_count = 0;
        int cow_count = 0;
        for(auto i = 0; i < guess.size(); ++i) {
            if(secret[i] == guess[i]) {
                bull_count += 1;
            } else {
                ++secret_record[secret[i] - '0'];
                ++guess_record[guess[i] - '0'];
            }
        }
        for(auto i = 0; i < 10; ++i) {
            cow_count += std::min(secret_record[i], guess_record[i]);
        }
        return std::to_string(bull_count) + "A" + std::to_string(cow_count) + "B";
    }
};

int main() {
    Solution s;
    string result = s.getHint("1807", "7810");
    cout << result << endl;
    result = s.getHint("1123", "0111");
    cout << result << endl;
    return 0;
}
