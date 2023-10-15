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

const int MM = 1e6+1;
const int M = 1e9+7;
unordered_map<int, int> dp[501];

int fun(int steps, int arrLen, int idx) {
    if (steps == 0 && idx == 0) return 1;
    else if (steps == 0) return 0;
    else if (dp[steps].count(idx) != 0) return dp[steps][idx];

    int ret = fun(steps-1, arrLen, idx);
    if (idx > 0) ret = (ret+fun(steps-1, arrLen, idx-1))%M;
    if (idx < arrLen-1) ret = (ret+fun(steps-1, arrLen, idx+1))%M;

    return dp[steps][idx] = ret;
}

int numWays(int steps, int arrLen) {
    return fun(steps, arrLen, 0);
}

int main() {
    cout << numWays(4, 2);

    return 0;
}