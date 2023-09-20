#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
using namespace std;

int minOperations(vector<int>& nums, int x) {
    int n = nums.size(), ret = INT_MAX;
    unordered_map<int, int> um; um[nums[0]] = 0;
    if (nums[0] == x) return 1;
    int sum = nums[0];
    for (int i = 1; i < n; i++) {
        sum += nums[i];
        if (sum == x) ret = i+1;
        um[sum] = i;
    }

    for (int i = n-1, sum = 0; i >= 0; i--) {
        sum += nums[i];
        if (sum == x) {
            ret = min(ret, n-i);
            continue;
        }
        if (um.count(x-sum) != 0 && um[x-sum] < i) ret = min(ret, n-i+um[x-sum]+1);
    }

    if (ret == INT_MAX) return -1;
    return ret;
}

int main() {
    vector<int> v = {3,2,20,1,1,3};
    cout << minOperations(v, 10);

    return 0;
}