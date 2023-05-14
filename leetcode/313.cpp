#include <vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) {
            return 1;
        }
        auto primes_count = primes.size();
        vector<int> nums;
        vector<int> prime_indices(n - 1, 0);
        nums.push_back(1);
        int start_num = 0;
        int last_min_value = 1;
        while(true) {
            int min_value = std::numeric_limits<int>::max();
            int min_index = 0;
            for(int j = start_num; j < nums.size(); ++j) {
                if(prime_indices[j] >= primes_count) {
                    continue;
                }
                int value = nums[j] * primes[prime_indices[j]];
                if(value < min_value) {
                    min_value = value;
                    min_index = j;
                    if(min_value == last_min_value) {
                        break;
                    }
                }
                if(prime_indices[j] == 0) {
                    break;
                }
            }
            prime_indices[min_index] += 1;
            while(start_num < prime_indices.size() && prime_indices[start_num] >= primes_count) {
                ++start_num;
            }
            if(min_value == last_min_value) {
                continue;
            }
            nums.push_back(min_value);
            if(nums.size() == n) {
                break;
            }
            last_min_value = min_value;
        }
        return nums[n - 1];
    }
};

int main() {
    Solution s;
    auto primes = vector<int>({7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251});
    int r = s.nthSuperUglyNumber(100000, primes);
    return 0;
}
