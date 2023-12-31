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

const int MM = 502;
int dp[MM][MM];

int fun(int x, int y, vector<int>& a, vector<int>& b) {
    if (dp[x][y] < 1e9) return dp[x][y];
    if (x >= a.size() || y >= b.size()) return 0;

    int ret = max(fun(x+1, y, a, b), fun(x, y+1, a, b));
    for (int i = x; i < a.size(); i++) {
        ret = max(ret, a[i]*b[y] + fun(i+1, y+1, a, b));
    }
    for (int i = y; i < b.size(); i++) {
        ret = max(ret, a[x]*b[i] + fun(x+1, i+1, a, b));
    }

    return dp[x][y] = ret;
}

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    memset(dp, 0x3f, sizeof(dp));
    int ret = fun(0, 0, nums1, nums2), mx = INT_MIN;

    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if ((mx = max(mx, nums1[i]*nums2[j])) >= 0) return ret;
        }
    }

    return mx;
}

int main() {
    // vector<int> a = {-5,3,-5,-3,1}, b = {-2,4,2,5,-5};
    // vector<int> a = {2,1,-2,5}, b = {3,0,-6};
    vector<int> a = {3,-2}, b = {2,-6,7};
    maxDotProduct(a, b);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            printf("(%d, %d - %d) ", a[i], b[j], dp[i][j]);
        }
        cout << endl;
    }
    // cout << maxDotProduct(a, b);

    return 0;
}