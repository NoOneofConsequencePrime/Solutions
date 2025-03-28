class Solution {
private:
    int m, n;
    vector<vector<int>> dp;

    int fun(int x, int y, vector<vector<char>>& grid) {
        if (dp[x][y] != -1) {return dp[x][y];}
        dp[x][y] = grid[x][y]-'0';
        int down = (x+1 >= m)? 0 : fun(x+1, y, grid);
        int right = (y+1 >= n)? 0 : fun(x, y+1, grid);
        down = right = min(down, right);
        if (dp[x][y] && down) {
            dp[x][y] = down + (grid[x+down][y+down] == '1');
        }

        return dp[x][y];
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size(); n = matrix[0].size();
        dp = vector(m, vector<int>(n, -1));

        int ret = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ret = max(ret, fun(i, j, matrix));
            }
        }

        return ret*ret;
    }
};