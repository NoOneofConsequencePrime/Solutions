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

const int MM = 2502;
int dp[MM];

int lengthOfLIS(vector<int>& nums) {
    fill(dp, dp+MM, 1);
    int n = nums.size(), ret = 1;

    for (int i = 2; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j]+1);
        }
        ret = max(ret, dp[i]);
    }

    return ret;
}

int main() {
    vector<int> v = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(v);

    return 0;
}