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
using namespace std;

const int MM = 1002, M = 1e9+7;
int dp[MM];

int fun(int n, int k, int target) {
    if (n <= 0 && target > 0) return 0;
    if (dp[target] != 0) return dp[target];
    printf("(%d, %d, %d): %d\n", n, k, target, dp[target]);

    for (int i = 1; i <= min(k, target); i++) {
        dp[target] = (dp[target]+fun(n-1, k, target-i))%M;
    }
    printf("--%d--\n", target);

    return dp[target];
}

int numRollsToTarget(int n, int k, int target) {
    dp[0] = 1;
    return fun(n, k, target);
}   

int main() {
    cout << numRollsToTarget(3,3,6);

    return 0;
}