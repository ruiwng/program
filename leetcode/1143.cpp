class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int len1 = static_cast<int>(text1.length());
		int len2 = static_cast<int>(text2.length());
		int** blocks = new int* [len1];
		for (int i = 0; i < len1; ++i) {
			blocks[i] = new int[len2];
			memset(blocks[i], 0, sizeof(int) * len2);
		}
		for (int i = 0; i < len1; ++i) {
			for (int j = 0; j < len2; ++j) {
				int sub_len1 = i > 0 ? blocks[i - 1][j] : 0;
				int sub_len2 = j > 0 ? blocks[i][j - 1] : 0;
				blocks[i][j] = max(sub_len1, sub_len2);
				if (text1[i] == text2[j]) {
					int sub_len3 = (i > 0 && j > 0) ? blocks[i - 1][j - 1] : 0;
					sub_len3 += 1;
					blocks[i][j] = max(blocks[i][j], sub_len3);
				}
			}
		}
		int r = blocks[len1 - 1][len2 - 1];
		for (int i = 0; i < len1; ++i) {
			delete[] blocks[i];
		}
		delete[] blocks;
		return r;
	}
};

int main() {
}
