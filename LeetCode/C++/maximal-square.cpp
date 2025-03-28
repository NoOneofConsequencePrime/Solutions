class Solution {
private:
    int m, n;
    vector<vector<int>> dp;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size(); n = matrix[0].size();
        dp = vector(m, vector<int>(n, -1));

        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = (matrix[i][j]=='1');
                if (dp[i][j]) {
                    int m = min((i-1>=0? dp[i-1][j]:0), (j-1>=0? dp[i][j-1]:0));
                    dp[i][j] = m + (matrix[i-m][j-m] == '1');
                }

                ret = max(ret, dp[i][j]);
            }
        }

        return ret*ret;
    }
};