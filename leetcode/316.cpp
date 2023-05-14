#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		int visited[26];
		memset(visited, 0, sizeof(visited));
		int freq[26];
		memset(freq, 0, sizeof(freq));
		for (auto& c : s) {
			++freq[c - 'a'];
		}
		auto length = s.length();
		stack<char> str;
		for (auto i = 0; i < length; ++i) {
			int index = s[i] - 'a';
			--freq[index];
			if (visited[index]) {
				continue;
			}
			while (!str.empty() && s[i] < str.top() && freq[str.top() - 'a'] > 0) {
				visited[str.top() - 'a'] = 0;
				str.pop();
			}
			str.push(s[i]);
			visited[index] = 1;
		}
		string res;
		while (!str.empty()) {
			res = str.top() + res;
			str.pop();
		}
		return res;
	}
};

int main() {
    Solution s;
    auto r = s.removeDuplicateLetters("leetcode");
    cout << r << endl;
    return 0;
}
