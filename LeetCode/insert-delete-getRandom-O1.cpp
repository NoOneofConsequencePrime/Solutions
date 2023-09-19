#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
using namespace std;

class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() {}
    
    bool insert(int val) {
        bool ret = true;
        if (st.count(val) > 0) ret = false;
        st.insert(val);
        return ret;
    }
    
    bool remove(int val) {
        bool ret = false;
        if (st.count(val) > 0) {
            ret = true;
        }
        st.erase(val);
        return ret;
    }
    
    int getRandom() {
        unordered_set<int>::iterator it = st.begin();
        int n = rand()%st.size();
        for (int i = 0; i < n; i++) it++;
        return *it;
    }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();

    return 0;
}