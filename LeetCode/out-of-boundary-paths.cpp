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

static const int M = 1e9+7;
int mx[4] = {1,-1,0,0}, my[4] = {0,0,1,-1};

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(maxMove+1, 0)));
    for (int idx = 1; idx <= maxMove; idx++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    int dx = i+mx[k], dy = j+my[k];
                    if (dx>=0 && dx<n) {
                        if (dy>=0 && dy<m) {dp[i][j][idx] += dp[dx][dy][idx-1];}
                        else {dp[i][j][idx]++;}
                    } else {dp[i][j][idx]++;}
                }
                dp[i][j][idx] %= M;
            }
        }
    }

    return dp[startColumn][startRow][maxMove];
}

int main() {
    cout << findPaths(2,2,2,0,0);

    return 0;
}