class Solution {
public:
	vector<string> printVertically(string s) {
		int len = static_cast<int>(s.length());
		vector<int> str_starts;
		int i = 0;
		int max_len = 0;
		while (true) {
			while (i < len && s[i] == ' ') {
				++i;
			}
			if (i == len) {
				break;
			}
			int str_start = i;
			str_starts.push_back(str_start);
			int current_len = 0;
			while (i < len && s[i] != ' ') {
				++i;
			}
			max_len = max(max_len, i - str_start);
			if (i == len) {
				break;
			}
		}
		vector<string> result;
		for (int m = 0; m < max_len; ++m) {
			string current_str;
			for (int n = 0; n < str_starts.size(); ++n) {
				if (str_starts[n] < len && s[str_starts[n]] != ' ') {
					current_str.push_back(s[str_starts[n]]);
					++str_starts[n];
				}
				else {
					current_str.push_back(' ');
				}
			}
			while (current_str.length() > 0 && current_str.back() == ' ') {
				current_str.pop_back();
			}
			result.push_back(current_str);
		}
		return result;
	}
};

int main() {
}
