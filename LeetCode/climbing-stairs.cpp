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

int dp[46];

int climbStairs(int n) {
    if (n <= 2) return n;
    if (dp[n] != 0) return dp[n];

    return dp[n] = climbStairs(n-1)+climbStairs(n-2);
}

int main() {
    cout << climbStairs(3);

    return 0;
}