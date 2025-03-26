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

int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int mx = nums1[0]*nums2[0];

    dp[0][0] = max(0, nums1[0]*nums2[0]);
    for (int i = 1; i < nums1.size(); i++) {
        mx = max(mx, nums1[i]*nums2[0]);
        dp[i][0] = max(dp[i-1][0], nums1[i]*nums2[0]);
    }
    for (int i = 1; i < nums2.size(); i++) {
        mx = max(mx, nums1[0]*nums2[i]);
        dp[0][i] = max(dp[0][i-1], nums1[0]*nums2[i]);
    }

    for (int i = 1; i < nums1.size(); i++) {
        for (int j = 1; j < nums2.size(); j++) {
            mx = max(mx, nums1[i]*nums2[j]);
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j-1] + nums1[i]*nums2[j]);
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
        }
    }

    int ret = dp[nums1.size()-1][nums2.size()-1];

    return (mx >= 0)? ret : mx;
}

int main() {
    vector<int> a = {1, -1}, b = {-1, 1};
    cout << maxDotProduct(a, b);

    return 0;
}