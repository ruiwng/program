#include <vector>
#include <unordered_set>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool isInserted = mElementsMap.insert({val, mElementsVec.size()}).second;
        if(isInserted)  {
            mElementsVec.push_back(val);
        }
        return isInserted;
    }
    
    bool remove(int val) {
        auto iter = mElementsMap.find(val);
        bool isExisted = iter != mElementsMap.end();
        if(isExisted) {
            mElementsMap[mElementsVec.back()] = iter->second;
            std::swap(mElementsVec[iter->second], mElementsVec.back());
            mElementsVec.pop_back();
            mElementsMap.erase(iter);
        }
        return isExisted;
    }
    
    int getRandom() {
        int random_index = static_cast<int>(float(rand()) / RAND_MAX * mElementsVec.size());
        return mElementsVec[random_index];
    }
    
private:
    unordered_map<int, int> mElementsMap;
    vector<int> mElementsVec;
};

int main() {
    
}
