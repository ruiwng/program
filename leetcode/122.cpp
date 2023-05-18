#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = static_cast<int>(prices.size());
        int i = 0;
        int total = 0;
        while(true) {
            while(i + 1 < len && prices[i] >= prices[i + 1]) {
                ++i;
            }
            if(i + 1 >= len) {
                break;
            }
            int buy_value = prices[i];
            i += 1;
            while(i + 1 < len && prices[i] <= prices[i + 1]) {
                ++i;
            }
            int sell_value = prices[i];
            total += sell_value - buy_value;
            if(i + 1 >= len) {
                break;
            }
        }
        return total;
    }
};

int main() {
    Solution s;
    vector<int> prices({1, 2, 3, 4, 5});
    int r = s.maxProfit(prices);
    return 0;
}
