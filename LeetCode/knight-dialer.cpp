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
using namespace std;

const int M = 1e9+7;
int mx[] = {1,1,-1,-1,2,2,-2,-2}, my[] = {2,-2,2,-2,1,-1,1,-1};

int knightDialer(int n) {
    long long dp[2][4][3] = {0};
    for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++) {
        if ((i==3&&j==0) || (i==3&&j==2)) continue;
        dp[1][i][j] = 1;
    }

    for (int idx = 1; idx < n; idx++) {
        int cur = idx%2, nxt = (idx+1)%2;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if ((i==3&&j==0) || (i==3&&j==2)) continue;
                for (int m = 0; m < 8; m++) {
                    int di = i+mx[m], dj = j+my[m];
                    if (di >= 0 && di <= 3 && dj >= 0 && dj <= 2 && !((di == 3 && dj == 0) || (di == 3 && dj == 2))) {
                        dp[nxt][di][dj] = (dp[nxt][di][dj]+dp[cur][i][j])%M;
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++) {
            if ((i==3&&j==0) || (i==3&&j==2)) continue;
            dp[cur][i][j] = 0;
        }
    }

    long long ret = 0;
    for (int i = 0; i < 4; i++) for (int j = 0; j < 3; j++) {
        if ((i==3&&j==0) || (i==3&&j==2)) continue;
        ret += dp[n%2][i][j];
    }

    return ret%M;
}

int main() {
    cout << knightDialer(3131);

    return 0;
}