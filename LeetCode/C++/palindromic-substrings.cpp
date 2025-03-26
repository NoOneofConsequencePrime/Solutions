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
public:
    int countSubstrings(string s) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = s.length(), ret = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < n-len+1; i++) {
                int j = i+len-1;
                if (len == 1) {
                    dp[i][j] = true;
                    ret++;
                } else if (len == 2 && s[j] == s[i]) {
                    dp[i][j] = true;
                    ret++;
                } else {
                    if (s[i] == s[j] && dp[i+1][j-1]) {
                        dp[i][j] = true;
                        ret++;
                    }
                }
            }
        }

        return ret;
    }
};

int main() {
    Solution ans;
    cout << ans.countSubstrings("aaa");

    return 0;
}