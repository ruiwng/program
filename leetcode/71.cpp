#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        int str_len = static_cast<int>(path.size());
        int i = 0;
        while(true) {
            while(i < str_len && path[i] == '/') {
                ++i;
            }
            if(i == str_len) {
                break;
            }
            string dir;
            while(i < str_len && path[i] != '/') {
                dir += path[i++];
            }
            if(dir == "..") {
                if(!dirs.empty()) {
                    dirs.pop_back();
                }
            } else if(dir != ".") {
                dirs.push_back(dir);
            }
            if(i == str_len) {
                break;
            }
        }
        string p;
        for(auto &dir: dirs) {
            p += "/" + dir;
        }
        if(p.empty()) {
            p = "/";
        }
        return p;
    }
};

int main() {
    Solution s;
    string path("/home//foo/");
    auto p = s.simplifyPath(path);
    printf("%s\n", p.c_str());
    return 0;
}
