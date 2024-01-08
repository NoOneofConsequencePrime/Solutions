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
unordered_map<long long, vector<int>> dp[MM];

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size(), ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long long chg = (long long)nums[i]-nums[j];
            if (dp[j].count(chg) != 0) {
                int tmp = 0;
                for (int x : dp[j][chg]) {
                    tmp += x+1;
                    ret += x+1;
                }
                dp[i][chg].push_back(tmp);
            } else dp[i][chg].push_back(0);
        }
    }

    return ret;
}

int main() {
    vector<int> v (1000,1000);
    cout << numberOfArithmeticSlices(v);

    return 0;
}