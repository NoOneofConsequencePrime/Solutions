#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int pre[n], suf[n];
    fill(pre, pre+n, 1); fill(suf, suf+n, 1);
    pre[0] *= nums[0]; suf[n-1] *= nums.back();
    for (int i = 1; i < n; i++) {
        pre[i] *= pre[i-1]*nums[i];
        suf[n-i-1] *= suf[n-i]*nums[n-i-1];
    }

    vector<int> ret;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0) ret.push_back(suf[1]);
        else if (i == nums.size()-1) ret.push_back(pre[nums.size()-2]);
        else ret.push_back(pre[i-1]*suf[i+1]);
    }

    return ret;
}

int main() {
    vector<int> v = {1,2,3,4};
    vector<int> ans = productExceptSelf(v);
    for (auto& x : ans) cout << x << " ";

    return 0;
}