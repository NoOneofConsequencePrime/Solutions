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

int dp[60];

int integerBreak(int n) {
    if (n == 1) return 1;
    if (dp[n] != 0) return dp[n];

    for (int i = 1; i < n; i++) {
        dp[n] = max(dp[n], max(integerBreak(n-i)*i, (n-i)*i));
    }

    return dp[n];
}

int main() {
    cout << integerBreak(10);
    for (int i = 1; i <= 10; i++) printf("%d: %d\n", i, dp[i]);

    return 0;
}