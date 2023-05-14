class Solution {
public:
	int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		int len1 = static_cast<int>(nums1.size());
		int len2 = static_cast<int>(nums2.size());
		int** record = new int* [len1];
		for (int i = 0; i < len1; ++i) {
			record[i] = new int[len2];
		}

		for (int i = 0; i < len1; ++i) {
			for (int j = 0; j < len2; ++j) {
				int crossLineCount1 = i > 0 ? record[i - 1][j] : 0;
				int crossLineCount2 = j > 0 ? record[i][j - 1] : 0;
				record[i][j] = max(crossLineCount1, crossLineCount2);
				if (nums1[i] == nums2[j]) {
					int crossLineCount3 = (i > 0 && j > 0) ? record[i - 1][j - 1] : 0;
					crossLineCount3 += 1;
					record[i][j] = max(record[i][j], crossLineCount3);
				}
			}
		}
		int r = record[len1 - 1][len2 - 1];
		for (int i = 0; i < len1; ++i) {
			delete [] record[i];
		}
		delete[]record;
		return r;
	}
};

int main() {
}
