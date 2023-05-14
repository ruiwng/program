#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void traverse(int num) {
        int start = num == 0 ? 1: 0;
        num *= 10;
        for(int i = start; i <= 9; ++i) {
            int t = num + i;
            if(t > mMax) {
                break;
            }
            mOrderedNums.push_back(num + i);
            traverse(num + i);
        }
    }
    vector<int> lexicalOrder(int n) {
        mOrderedNums.clear();
        mMax = n;
        traverse(0);
        return mOrderedNums;
    }
private:
    int mMax;
    vector<int> mOrderedNums;
};

int main() {
    Solution s;
    auto r = s.lexicalOrder(480);
    return 0;
}
