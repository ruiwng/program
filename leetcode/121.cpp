#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = static_cast<int>(prices.size());
        int k = 0;
        int min_price = std::numeric_limits<int>::max();
        int max_profit = 0;
        for(int i = 0; i < len; ++i) {
            if(prices[i] < min_price) {
                min_price = prices[i];
            } else if(prices[i] - min_price > max_profit) {
                max_profit = prices[i] - min_price;
            }
        }
        return max_profit;
    }
};

int main() {
    Solution s;
    vector<int> prices({7,6,4,3,1});
    int r = s.maxProfit(prices);
    return 0;
}

