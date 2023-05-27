#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = static_cast<int>(gas.size());
        vector<int> left_gas(len * 2);
        for(int i = 0; i < len; ++i) {
            left_gas[i] = left_gas[i + len] = gas[i] - cost[i];
        }
        int left_gas_len = len << 1;
        int left = 0;
        int right = 0;
        int gas_amount = 0;
        while(true) {
            while(right < left_gas_len && (gas_amount + left_gas[right]) >= 0) {
                gas_amount += left_gas[right];
                ++right;
            }
            if(right >= left_gas_len) {
                break;
            }
            ++right;
            left = right;
            gas_amount = 0;
            if(left >= len) {
                break;
            }
        }
        
        if(right - left >= len) {
            return left;
        } else {
            return -1;
        }
    }
};


int main() {
    Solution s;
    vector<int> gas({2,3,4});
    vector<int> cost({3,4,3});
    int r = s.canCompleteCircuit(gas, cost);
    return 0;
}
