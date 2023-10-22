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

int maximumScore(vector<int>& nums, int k) {
    if (nums.size() == 1) return nums[0];

    int ret = -1;
    vector<pair<int, int>> pre, suf;

    for (int i = k-1, preMi = nums[k]; i >= 0; i--) {
        if (nums[i] < preMi) {
            pre.push_back({preMi, k-i});
            ret = max(ret, preMi*(k-i));
            preMi = nums[i];
        }
        if (i == 0) {
            pre.push_back({min(preMi, nums[i]), k-i+1});
            ret = max(ret, min(preMi, nums[i])*(k-i+1));
        }
    }
    reverse(pre.begin(), pre.end());
    for (int i = k+1, preMi = nums[k]; i < nums.size(); i++) {
        if (nums[i] < preMi) {
            suf.push_back({preMi, i-k});
            ret = max(ret, preMi*(i-k));
            preMi = nums[i];
        }
        if (i == nums.size()-1) {
            suf.push_back({min(preMi, nums[i]), i-k+1});
            ret = max(ret, min(preMi, nums[i])*(i-k+1));
        }
    }

    if (pre.size() == 0 || suf.size() == 0) return ret;

    for (int i = 0; i < suf.size(); i++) {
        int idx = lower_bound(pre.begin(), pre.end(), suf[i])-pre.begin();
        int prod = (pre[min((int)pre.size()-1, idx)].second + suf[i].second - 1) * suf[i].first;
        ret = max(ret, prod);
    }
    for (int i = pre.size()-1; i >= 0; i--) {
        int idx = upper_bound(suf.begin(), suf.end(), pre[i], greater<pair<int, int>>())-suf.begin()-1;
        int prod = (suf[max(idx, 0)].second + pre[i].second - 1) * pre[i].first;
        ret = max(ret, prod);
    }

    return ret;
}

int main() {
    vector<int> v = {5,5,4,5,4,1,1,1};
    // 1 4 3 7 4 5
    // 1 3 3 7
    // - - - 7 4 4
    cout << maximumScore(v, 0);

    return 0;
}