#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
#include <map>
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    map<int, int> mp;
    for (int& x : arr) mp[x]++;

    int ret = (mp.count(1)==1);
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ret += min((*it).first-ret, (*it).second);
    }
    
    return ret;
}

int main() {
    vector<int> v = {2, 2, 1, 2, 1};
    cout << maximumElementAfterDecrementingAndRearranging(v);

    return 0;
}