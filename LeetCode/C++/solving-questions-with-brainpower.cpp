typedef long long ll;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n, 0ll);
        dp[n-1] = questions[n-1][0];
        for (int i = n-2; i >= 0; i--) {
            int rIdx = i+questions[i][1]+1;
            dp[i] = max(dp[i+1], (ll)questions[i][0]+((rIdx<n)? dp[rIdx]:0ll));
        }

        return dp[0];
    }
};