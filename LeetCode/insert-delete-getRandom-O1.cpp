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
private:
    unordered_map<int, int> um;
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (um.count(val) == 0) {
            um[val] = v.size();
            v.push_back(val);

            return true;
        } else return false;
    }
    
    bool remove(int val) {
        if (um.count(val) > 0) {
            int vi = um[val], bv = v.back();
            swap(um[val], um[bv]);
            swap(v[vi], v[v.size()-1]);
            v.pop_back(); um.erase(val);

            return true;
        } return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(1) << '\n';
    cout << obj->remove(2) << '\n';
    cout << obj->insert(2) << '\n';
    cout << obj->getRandom() << '\n';
    cout << obj->remove(1) << '\n';
    cout << obj->insert(2) << '\n';
    cout << obj->getRandom() << '\n';

    return 0;
}