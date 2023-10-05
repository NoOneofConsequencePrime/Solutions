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

vector<int> majorityElement(vector<int>& nums) {
    vector<int> ret;
    unordered_map<int, int> um;
    for (int& x : nums) {
        um[x]++;
        if (um[x] > (int)nums.size()/3) {
            ret.push_back(x);
            um[x] = INT_MIN;
        }
    }

    return ret;
}

int main() {
    vector<int> v = {3, 3};
    vector<int> ans = majorityElement(v);
    for (auto& x : ans) cout << x << " ";

    return 0;
}