#include <vector>
using namespace std;

struct Candy {
    Candy(int r, int p): rating(r), pos(p) {}
    int rating;
    int pos;
    bool operator<(const Candy& rhs) const {
        return rating < rhs.rating;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = static_cast<int>(ratings.size());
        vector<int> candies(len, -1);
        
        vector<Candy> candy_array;
        candy_array.reserve(len);
        for(int i = 0; i < len; ++i) {
            candy_array.push_back(Candy(ratings[i], i));
        }
        sort(candy_array.begin(), candy_array.end());
        
        int total_candy_count = 0;
        for(int i = 0; i < len; ++i) {
            int pos = candy_array[i].pos;
            int left = pos - 1;
            int right = pos + 1;
            int candy_count = 1;
            if(left >= 0 && candies[left] != -1 && ratings[pos] > ratings[left]) {
                candy_count = candies[left] + 1;
            }
            if(right < len && candies[right] != -1 && ratings[pos] > ratings[right]) {
                candy_count = std::max(candy_count, candies[right] + 1);
            }
            candies[pos] = candy_count;
            total_candy_count += candy_count;
        }
        
        return total_candy_count;
    }
};

int main() {
    Solution s;
    vector<int> ratings({1,2,2});
    int r = s.candy(ratings);
    return 0;
}
