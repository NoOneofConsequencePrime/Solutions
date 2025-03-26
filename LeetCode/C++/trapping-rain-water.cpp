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
    int trap(vector<int>& height) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = height.size();
        vector<int> pre(n, INT_MIN), suf(n, INT_MIN);
        for (int i = 0, ma = INT_MIN; i < n; i++) {
            pre[i] = ma;
            ma = max(ma, height[i]);
        }
        for (int i = n-1, ma = INT_MIN; i >= 0; i--) {
            suf[i] = ma;
            ma = max(ma, height[i]);
        }

        int ret = 0;
        for (int i = 1; i < n-1; i++) {
            int mi = min(pre[i], suf[i]);
            if (mi >= height[i]) {ret += mi-height[i];}
        }

        return ret;
    }
};

int main() {
    Solution ans;
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << ans.trap(v);

    return 0;
}