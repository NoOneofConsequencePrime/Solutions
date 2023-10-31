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

vector<int> dp[5];
const int M = 1e9+7;

int countVowelPermutation(int n) {
    for (int i = 0; i < 5; i++) {
        dp[i].resize(n, 0); dp[0][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = (dp[i-1][0]+dp[i-1][2])%M;
        dp[i][2] = ((dp[i-1][0]+dp[i-1][1])%M+(dp[i-1][3]+dp[i-1][4])%M)%M;
        dp[i][3] = (dp[i-1][2]+dp[i-1][4])%M;
        dp[i][4] = dp[i-1][0];
    }

    return (((dp[n-1][0]+dp[n-1][1])%M+(dp[n-1][2]+dp[n-1][3])%M)%M+dp[n-1][4])%M;
}

int main() {
    cout << countVowelPermutation(1);

    return 0;
}