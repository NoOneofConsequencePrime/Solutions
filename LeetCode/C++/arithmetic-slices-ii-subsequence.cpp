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
unordered_map<int, vector<int>> mp;
int dp[MM][MM];

int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size(), ret = 0;
    for (int i = 0; i < n; i++) mp[nums[i]].push_back(i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long long prev = 2ll*nums[j]-nums[i];
            if (prev < INT_MIN || prev > INT_MAX) continue;
            if (mp.count(prev) != 0) {
                vector<int>& v = mp[prev];
                for (int x : v) {
                    if (x >= j) break;
                    dp[i][j] += dp[j][x]+1;
                }
            }
            ret += dp[i][j];
        }
    }

    return ret;
}

int main() {
    vector<int> v = {2,2,3,4};
    cout << numberOfArithmeticSlices(v);

    return 0;
}