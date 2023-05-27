#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int j = 0;
        int k = 0;
        vector<string> result;
        while(true) {
            int word_length = 0;
            while(k < words.size()) {
                int current_word_length = static_cast<int>(words[k].length());
                int total_length = word_length + current_word_length;
                if(k != j) {
                    total_length += 1;
                }
                if(total_length > maxWidth) {
                    break;
                }
                word_length = total_length;
                ++k;
            }
            int left_space_chars = maxWidth - word_length;
            int word_count = k - j;
            vector<int> space_char_array;
            if(word_count == 1) {
                space_char_array.push_back(left_space_chars);
            } else if(k == words.size()) {
                for(int i = 0; i < word_count - 1; ++i) {
                    space_char_array.push_back(1);
                }
                space_char_array.push_back(left_space_chars);
            } else {
                int space_count = word_count - 1;
                int space_char_total = left_space_chars + space_count;
                int t = space_char_total / space_count;
                int m = space_char_total % space_count;
                for(int i = 0; i < space_count; ++i) {
                    if(i < m) {
                        space_char_array.push_back(t + 1);
                    } else {
                        space_char_array.push_back(t);
                    }
                }
                space_char_array.push_back(0);
            }
            string str;
            for(int i = 0; i < word_count; ++i) {
                str += words[j + i];
                str += string(space_char_array[i], ' ');
            }
            result.push_back(str);
            if(k == words.size()) {
                break;
            }
            j = k;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> words({"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"});
    int maxWidth = 20;
    auto r = s.fullJustify(words, maxWidth);
    for(int i = 0; i < r.size(); ++i) {
        cout << r[i] << '|' << endl;
    }
    return 0;
}
