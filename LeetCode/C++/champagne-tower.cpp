#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;

double dp[102][102];

double fun(int poured, int query_row, int query_glass) {
    if (query_glass < 0 || query_glass > query_row) return 0;
    if (query_row == 0) return poured;
    if (dp[query_row][query_glass] >= 0) return dp[query_row][query_glass];

    double l = fun(poured, query_row-1, query_glass-1);
    if (l >= 1) {
        l--; l /= 2;
    } else l = 0;
    double r = fun(poured, query_row-1, query_glass);
    if (r >= 1) {
        r--; r /= 2;
    } else r = 0;
    return dp[query_row][query_glass] = l+r;
}

double champagneTower(int poured, int query_row, int query_glass) {
    memset(dp, -0x3f, sizeof(dp));
    return min(1.0, fun(poured, query_row, query_glass));
}

int main() {
    cout << champagneTower(100, 85, 39);

    return 0;
}