#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> st;
    for (int i = 0; i < nums.size(); i++) {
        if (st.count(nums[i]) != 0) return true;
        st.insert(nums[i]);
        if (i >= k) st.erase(nums[i-k]);
    }

    return false;
}

int main() {
    vector<int> v = {1,2,3,1};
    cout << containsNearbyDuplicate(v, 3);

    return 0;
}