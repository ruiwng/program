class Solution {
public:
    double myPowImp(double x, long long n) {
        if(n == 0) {
            return 1.0;
        } else if(n == 1) {
            return x;
        }
        long long k = n >> 1;
        double t = myPowImp(x, k);
        if(n & 1) {
            return t * t * x;
        } else {
            return t * t;
        }
    }
    double myPow(double x, int n) {
        long long t = n;
        bool is_negative = false;
        if(t < 0) {
            is_negative = true;
            t = -t;
        }
        double r = myPowImp(x, t);
        return is_negative? (1.0 / r): r;
    }
};

int main() {
    Solution s;
    double r = s.myPow(2.00000, -2);
    return 0;
}
