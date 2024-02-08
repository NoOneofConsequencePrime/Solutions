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
    int fun(int n, vector<int> &dp) {
        if (n == 0) {return 0;}
        if (dp[n] < 1e5) {return dp[n];}
        
        for (int i = 1; i <= sqrt(n); i++) {
            dp[n] = min(dp[n], fun(n-i*i, dp)+1);
        }

        return dp[n];
    }
public:
    int numSquares(int n) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int> dp(n+1, INT_MAX);

        return fun(n, dp);
    }
};

int main() {
    Solution ans;
    cout << ans.numSquares(12);

    return 0;
}