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

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<ll> prevMi(n), dp(n, 0);
    stack<pii> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.top().f>arr[i]) {stk.pop();}
        if (stk.empty()) {
            prevMi[i] = -1;
        } else {
            prevMi[i] = stk.top().s;
        }
        stk.push({arr[i], i});
    }

    ll ret = 0;
    for (int i = 0; i < n; i++) {
        if (prevMi[i] == -1) {ret += dp[i]=(ll)arr[i]*(i+1);}
        else {
            dp[i] += (ll)arr[i]*(i-prevMi[i]);
            dp[i] += dp[prevMi[i]];
            ret += dp[i];
        }
    }

    return ret%(ll)(1e9+7);
}

int main() {
    vector<int> v = {11,81,94,43,3};
    cout << sumSubarrayMins(v);

    return 0;
}