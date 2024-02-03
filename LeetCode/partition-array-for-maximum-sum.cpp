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
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = arr.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            int ma = INT_MIN;
            for (int j = 1; j <= k; j++) {
                int idx = i-j+1;
                if (idx < 0) {break;}
                ma = max(ma, arr[idx]);
                if (idx == 0) {dp[i] = max(dp[i], ma*j);}
                else {dp[i] = max(dp[i], dp[idx-1]+ma*j);}
            }
        }

        return dp[n-1];
    }
};

int main() {
    Solution ans;
    vector<int> v = {1,4,1,5,7,3,6,1,9,9,3};
    cout << ans.maxSumAfterPartitioning(v, 4);

    return 0;
}