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
    bool chk[2002] = {false};
    vector<int> a, b;
    for (auto& x : nums1) chk[x+1000] = true;
    for (auto& x : nums2) {
        if (!chk[x+1000]) {
            a.push_back(x);
            chk[x+1000] = true;
        }
    }
    memset(chk, false, sizeof(chk));
    for (auto& x : nums2) chk[x+1000] = true;
    for (auto& x : nums1) {
        if (!chk[x+1000]) {
            b.push_back(x);
            chk[x+1000] = true;
        }
    }

    return {b, a};
}

int main() {
    vector<int> a = {1,2,3}, b = {2,4,6};
    vector<vector<int>> ans = findDifference(a, b);
    for (auto& v : ans) {
        for (auto& x : v) cout << x << " ";
        cout << endl;
    }

    return 0;
}