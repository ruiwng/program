class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) {
            return 0;
        } else if(x < 4) {
            return 1;
        } else if(x < 9) {
            return 2;
        }
        int lower = 2;
        int upper = x >> 1;
        while(lower + 1 < upper) {
            int middle = (lower + upper) >> 1;
            long long t = static_cast<long long>(middle) * middle;
            if(t <= x) {
                lower = middle;
            } else {
                upper = middle;
            }
        }
        return lower;
    }
};

int main() {
    Solution s;
    int res = s.mySqrt(9);
    return 0;
}
