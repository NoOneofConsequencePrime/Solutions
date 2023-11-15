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

vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> st, bk;
    vector<int> a, b;
    for (auto& x : nums1) st.insert(x);
    for (auto& x : nums2) {
        if (!st.count(x) && !bk.count(x)) a.push_back(x);
        bk.insert(x);
    }
    st.clear(); bk.clear();
    for (auto& x : nums2) st.insert(x);
    for (auto& x : nums1) {
        if (!st.count(x) && !bk.count(x)) b.push_back(x);
        bk.insert(x);
    }

    return {b, a};
}

int main() {
    vector<int> a = {1,2,3}, b = {2,4,6};
    vector<vector<int>> ans = findDifference(a, b);
    for (auto& v : ans) printf("%d %d\n", v[0], v[1]);

    return 0;
}