typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

class Solution {
private:
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l < n-len+1; l++) {
                int r = l+len-1;
                if (len == 1) {
                    dp[l][r] = true;
                    continue;
                }
                if (len == 2) {
                    dp[l][r] = (s[l] == s[r]);
                    continue;
                }
                dp[l][r] = (s[l] == s[r]) && dp[l+1][r-1];
            }
        }

        pii ret = {0, 0};
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (!dp[i][j]) {continue;}
                if (j-i > ret.s-ret.f) {ret = {i, j};}
            }
        }

        return s.substr(ret.f, ret.s-ret.f+1);
    }
};