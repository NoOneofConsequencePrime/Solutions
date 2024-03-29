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

const int MM = 1e4+2;
int dp[MM];

int coinChange(vector<int>& coins, int amount) {
    memset(dp, 0x3f, sizeof(dp));
    int n = coins.size();
    dp[0] = 0;
    for (int val : coins) {
        for (int i = 1; i <= amount; i++) {
            if (i-val >= 0) {dp[i] = min(dp[i], dp[i-val]+1);}
        }
    }

    return (dp[amount] > 1e9)? -1 : dp[amount];
}

int main() {
    vector<int> v = {1,2,5};
    cout << coinChange(v, 11);

    return 0;
}