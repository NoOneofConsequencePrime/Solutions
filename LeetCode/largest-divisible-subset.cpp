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
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

class Solution {
private:
    void fun(int n, vector<int> &nums, vector<vector<int>> &dp) {
        if (!dp[n].empty()) {return;}
        cout << "c";
        dp[n].push_back(nums[n]);

        for (int i = 0; i < n; i++) {
            fun(i, nums, dp);
            if (nums[i]%nums[n] == 0 || nums[n]%nums[i] == 0) {
                if (dp[i].size()+1 > dp[n].size()) {
                    dp[n] = dp[i];
                    dp[n].push_back(nums[n]);
                }
            }
        }
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n, vector<int>());
        fun(n-1, nums, dp);

        vector<int> ret;
        for (auto &v : dp) {
            if (v.size() > ret.size()) {ret = v;}
        }

        return ret;
    }
};

int main() {
    Solution ans;
    vector<int> v = {1,2,4,8,10};
    vector<int> ret = ans.largestDivisibleSubset(v);
    for (int x : ret) {cout << x << " ";}

    return 0;
}