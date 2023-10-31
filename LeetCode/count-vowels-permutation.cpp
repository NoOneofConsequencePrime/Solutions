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

int fun(int n, char c) {
    if (n == 1) return 1;

    switch (c) {
        case 'a':
            if (dp[0][n-1] != 0) return dp[0][n-1];
            return dp[0][n-1] = fun(n-1, 'e');
        case 'e':
            if (dp[1][n-1] != 0) return dp[1][n-1];
            return dp[1][n-1] = (fun(n-1, 'a')+fun(n-1, 'i'))%M;
        case 'i':
            if (dp[2][n-1] != 0) return dp[2][n-1];
            return dp[2][n-1] = ((fun(n-1, 'a')+fun(n-1,'e'))%M+(fun(n-1, 'o')+fun(n-1, 'u'))%M)%M;
        case 'o':
            if (dp[3][n-1] != 0) return dp[3][n-1];
            return dp[3][n-1] = (fun(n-1, 'i')+fun(n-1, 'u'))%M;
        case 'u':
            if (dp[4][n-1] != 0) return dp[4][n-1];
            return dp[4][n-1] = fun(n-1, 'a');
    }

    return -1;
}

int countVowelPermutation(int n) {
    for (int i = 0; i < 5; i++) dp[i].resize(n, 0);
    return (((fun(n, 'a')+fun(n, 'e'))%M+(fun(n, 'i')+fun(n, 'o'))%M)%M+fun(n, 'u'))%M;
}

int main() {
    cout << countVowelPermutation(2);

    return 0;
}