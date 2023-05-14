#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        mNumSize = static_cast<int>(nums.size());
        mSegmentTree.resize(mNumSize * 4);
        build(nums, 0, 0, mNumSize - 1);
    }
    void build(vector<int>& nums, int index, int left_range, int right_range) {
        if(left_range == right_range) {
            mSegmentTree[index] = nums[left_range];
            return;
        }
        int middle_range = (left_range + right_range) >> 1;
        int left_child = (index << 1) + 1;
        int right_child = left_child + 1;
        build(nums, left_child, left_range, middle_range);
        build(nums, right_child, middle_range + 1, right_range);
        mSegmentTree[index] = mSegmentTree[left_child] + mSegmentTree[right_child];
    }
    
    void update(int pos, int left_range, int right_range, int index, int val) {
        if(left_range == right_range) {
            mSegmentTree[pos] = val;
            return;
        }
        int middle = (left_range + right_range) >> 1;
        int left_child = (pos << 1) + 1;
        int right_child = left_child + 1;
        if(index <= middle) {
            update(left_child, left_range, middle, index, val);
        } else {
            update(right_child, middle + 1, right_range, index, val);
        }
        mSegmentTree[pos] = mSegmentTree[left_child] + mSegmentTree[right_child];
    }
    
    int query(int pos, int left_range, int right_range, int left, int right) {
        if(left_range == left && right_range == right) {
            return mSegmentTree[pos];
        }
        int middle = (left_range + right_range) >> 1;
        int left_child = (pos << 1) + 1;
        int right_child = left_child + 1;
        if(right <= middle) {
            return query(left_child, left_range, middle, left, right);
        } else if(left > middle) {
            return query(right_child, middle + 1, right_range, left, right);
        } else {
            return query(left_child, left_range, middle, left, middle) + query(right_child, middle + 1, right_range, middle + 1, right);
        }
    }
    
    void update(int index, int val) {
        update(0, 0, mNumSize - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, mNumSize - 1, left, right);
    }
private:
    int mNumSize;
    vector<int> mSegmentTree;
};

int main() {
    vector<int> nums{1, 3, 5};
    auto p = new NumArray(nums);
    int param = p->sumRange(0, 2);
    p->update(0, 2);
    param = p->sumRange(0, 2);
    p->update(2, 4);
    param = p->sumRange(0, 2);
    return 0;
}
