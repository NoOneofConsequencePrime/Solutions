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

const int MM = 1002;
unordered_map<int, int> dp[MM];

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size(), ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long long chg = (long long)nums[i]-nums[j];
            if (chg > INT_MAX || chg < INT_MIN) continue;

            dp[i][chg]++;
            if (dp[j].count(chg) != 0) {
                dp[i][chg] += dp[j][chg];
                ret += dp[j][chg];
            }
        }
    }

    return ret;
}

int main() {
    vector<int> v = {2,2,3,4};
    cout << numberOfArithmeticSlices(v);

    return 0;
}