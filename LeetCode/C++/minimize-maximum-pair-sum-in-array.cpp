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

int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ret = -1, n = nums.size();
    for (int i = 0; i < n/2; i++) ret = max(ret, nums[i]+nums[n-i-1]);

    return ret;
}

int main() {
    vector<int> v = {3,5,4,2,4,6};
    cout << minPairSum(v);

    return 0;
}