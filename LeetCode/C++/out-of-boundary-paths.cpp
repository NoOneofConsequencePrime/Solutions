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

const int M = 1e9+7;
const int MM = 52;
int mx[4] = {1,-1,0,0}, my[4] = {0,0,1,-1};
int dp[MM][MM][MM];

int fun(int n, int m, int x, int y, int move) {
    if (dp[move][x][y] >= 0) {return dp[move][x][y];}
    dp[move][x][y] = 0;
    if (move <= 0) {return 0;}
    for (int i = 0; i < 4; i++) {
        int dx = x+mx[i], dy = y+my[i];
        if (dx<0 || dx>=n || dy<0 || dy>=m) {dp[move][x][y]++;}
        else {dp[move][x][y] = (dp[move][x][y]+fun(n, m, dx, dy, move-1))%M;}
    }

    return dp[move][x][y]%=M;
}

int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    memset(dp, -0x3f, sizeof(dp));
    return fun(m, n, startRow, startColumn, maxMove);
}

int main() {
    cout << findPaths(2,2,2,0,0);

    return 0;
}