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

const int MM = 1002;
const int M = 1e9+7;
int dp[MM][MM];

int kInversePairs(int n, int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0) {dp[i][j] = 1;}
            for (int k = 0; k<=i && j+k<=1000; k++) {
                dp[i+1][j+k] = (dp[i+1][j+k]+dp[i][j])%M;
            }
        }
    }

    return dp[n][k];
}

int main() {
    cout << kInversePairs(3, 1);

    return 0;
}