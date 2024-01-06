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

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int lengthOfLIS(vector<int>& nums) {
    vector<int> v = {nums[0]};
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (v.back() < nums[i]) v.push_back(nums[i]);
        else {
            int lb = lower_bound(v.begin(), v.end(), nums[i])-v.begin();
            v[lb] = nums[i];
        }
    }

    return v.size();
}

int main() {
    vector<int> v = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(v);

    return 0;
}