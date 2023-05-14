class NumArray {
public:
	NumArray(vector<int>& nums) {
		int sum = 0;
		mSums.push_back(sum);
		for (auto& n : nums) {
			sum += n;
			mSums.push_back(sum);
		}
	}

	int sumRange(int left, int right) {
		return mSums[right + 1] - mSums[left];
	}
private:
	vector<int> mSums;
};

int main() {
}
