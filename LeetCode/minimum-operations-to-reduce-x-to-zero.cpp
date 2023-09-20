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

int minOperations(vector<int>& nums, int x) {
    int target = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
    if (target == x) return nums.size();
    target -= x;
    if (target < 0) return -1;

    int ret = -1;
    for (int a = 0, b = 0, sum = 0; b < n; b++) {
        sum += nums[b];
        while (sum > target && a < b) {
            sum -= nums[a];
            a++;
        }
        if (sum == target) ret = max(ret, b-a+1);
    }

    return (ret == -1)? -1 : n-ret;
}

int main() {
    vector<int> v = {1, 2, 3};
    cout << minOperations(v, 6);

    return 0;
}