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

int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.length(), n2 = text2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, 0));

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (text1[i] == text2[j]) {
                if (i > 0 && j > 0) {dp[i][j] = dp[i-1][j-1];}
                dp[i][j]++;
            }
            if (i > 0) {dp[i][j] = max(dp[i][j], dp[i-1][j]);}
            if (j > 0) {dp[i][j] = max(dp[i][j], dp[i][j-1]);}
        }
    }

    return dp[n1-1][n2-1];
}

int main() {
    cout << longestCommonSubsequence("abcde", "ace");

    return 0;
}