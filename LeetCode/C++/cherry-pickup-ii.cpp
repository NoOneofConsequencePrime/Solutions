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
    int fun(int n, int m, int lvl, int a, int b, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
        if (lvl >= n) {return 0;}
        if (a >= m || a < 0 || b >= m || b < 0) {return 0;}
        if (dp[lvl][a][b] >= 0) {return dp[lvl][a][b];}

        for (int i = a-1; i <= a+1; i++) {
            for (int j = b-1; j <= b+1; j++) {
                dp[lvl][a][b] = max(dp[lvl][a][b], fun(n, m, lvl+1, i, j, grid, dp));
            }
        }
        
        dp[lvl][a][b] += grid[lvl][a];
        if (a != b) {dp[lvl][a][b] += grid[lvl][b];}

        return dp[lvl][a][b];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return fun(n, m, 0, 0, m-1, grid, dp);
    }
};

int main() {
    Solution ans;
    vector<vector<int>> grid = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };
    cout << ans.cherryPickup(grid);

    return 0;
}