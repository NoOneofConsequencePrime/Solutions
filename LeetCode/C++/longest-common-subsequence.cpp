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
    if (text1.length() < text2.length()) {swap(text1, text2);}// text1 longer
    int n1 = text1.length(), n2 = text2.length();
    vector<vector<int>> dp(2, vector<int>(n2, 0));

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (text1[i] == text2[j]) {
                if (i > 0 && j > 0) {dp[1][j] = dp[0][j-1];}
                dp[1][j]++;
            }
            if (i > 0) {dp[1][j] = max(dp[1][j], dp[0][j]);}
            if (j > 0) {dp[1][j] = max(dp[1][j], dp[1][j-1]);}
        }
        swap(dp[0], dp[1]);
        fill(dp[1].begin(), dp[1].end(), 0);
    }

    return dp[0][n2-1];
}

int main() {
    cout << longestCommonSubsequence("abcde", "ace");

    return 0;
}