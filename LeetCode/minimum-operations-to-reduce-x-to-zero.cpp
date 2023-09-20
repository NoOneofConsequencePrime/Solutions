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
    vector<int> psa; psa.push_back(nums[0]);
    if (psa[0] == x) return 1;
    for (int i = 1; i < n; i++) {
        psa.push_back(psa[i-1]+nums[i]);
        if (psa[i] == x) ret = i+1;
    }

    for (int i = n-1, sum = 0; i >= 0; i--) {
        sum += nums[i];
        if (sum == x) {
            ret = min(ret, n-i);
            continue;
        }
        vector<int>::iterator low = lower_bound(psa.begin(), psa.end(), x-sum), up = upper_bound(psa.begin(), psa.end(), x-sum);
        int idx = low-psa.begin();
        if (low != up && idx < i) ret = min(ret, n-i+idx+1);
    }

    if (ret == INT_MAX) return -1;
    return ret;
}

int main() {
    vector<int> v = {1,1,4,2,3};
    cout << minOperations(v, 5);

    return 0;
}