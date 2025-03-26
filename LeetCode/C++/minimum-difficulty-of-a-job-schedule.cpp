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

const int MM = 302;
int dp[12][MM];

int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if (d > n) return -1;
    else if (d == 1) {
        int ret = 0;
        for (int x : jobDifficulty) ret = max(ret, x);
        return ret;
    }

    for (int i = 0; i < n-1; i++) {
        int mxl = 0;
        for (int j = 0; j <= i; j++) mxl = max(mxl, jobDifficulty[j]);
        dp[1][i] = mxl;
    }

    for (int idx = 2; idx <= d-1; idx++) {
        for (int i = idx-1; i < n-1; i++) {
            int tmp = INT_MAX, mxm = 0;
            for (int j = i-1; j >= idx-2; j--) {
                mxm = max(mxm, jobDifficulty[j+1]);
                tmp = min(tmp, dp[idx-1][j]+mxm);
            }
            dp[idx][i] = tmp;
        }
    }

    int ret = INT_MAX, mxr = 0;
    for (int i = n-1; i >= d-1; i--) {
        mxr = max(mxr, jobDifficulty[i]);
        ret = min(ret, dp[d-1][i-1]+mxr);
    }

    return ret;
}

int main() {
    vector<int> v = {1,1,1};
    cout << minDifficulty(v, 3);

    return 0;
}