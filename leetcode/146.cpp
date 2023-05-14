#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
    void printList() {
        for(auto iter = mLRUList.begin(); iter != mLRUList.end(); ++iter) {
            printf(" <%d, %d>", iter->first, iter->second);
        }
        printf("\n");
    }
public:
    LRUCache(int capacity) {
        mSize = 0;
        mCapacity = capacity;
    }
    
    int get(int key) {
        auto iter = mLRUMap.find(key);
        if(iter == mLRUMap.end()) {
            return -1;
        }
        auto& list_iter = iter->second;
        int value = list_iter->second;
        mLRUList.erase(list_iter);
        mLRUList.insert(mLRUList.begin(), {key, value});
        mLRUMap[key] = mLRUList.begin();
        // printList();
        return value;
    }
    
    void put(int key, int value) {
        auto iter = mLRUMap.find(key);
        if(iter != mLRUMap.end()) {
            auto& list_iter = iter->second;
            mLRUList.erase(list_iter);
        } else {
            if(mSize == mCapacity) {
                auto leastUse = mLRUList.back();
                mLRUMap.erase(mLRUMap.find(leastUse.first));
                mLRUList.pop_back();
            } else {
                ++mSize;
            }
        }
        mLRUList.insert(mLRUList.begin(), {key, value});
        mLRUMap[key] = mLRUList.begin();
        // printList();
    }
private:
    int mCapacity;
    int mSize;
    unordered_map<int, list<pair<int, int>>::iterator> mLRUMap;
    list<pair<int, int>> mLRUList;
};

int main() {
    LRUCache* lRUCache = new LRUCache(2);
    lRUCache->put(1, 1); // cache is {1=1}
    lRUCache->put(2, 2); // cache is {1=1, 2=2}
    printf("%d\n", lRUCache->get(1));    // return 1
    lRUCache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    printf("%d\n", lRUCache->get(2));    // returns -1 (not found)
    lRUCache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    printf("%d\n", lRUCache->get(1));    // return -1 (not found)
    printf("%d\n", lRUCache->get(3));    // return 3
    printf("%d\n", lRUCache->get(4));    // return 4
    return 0;
}
