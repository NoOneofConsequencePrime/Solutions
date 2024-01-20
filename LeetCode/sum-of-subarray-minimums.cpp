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

const int M = 1e9+7;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size(), ret = 0;
    vector<int> dp(n, 0);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && arr[stk.top()]>arr[i]) {stk.pop();}
        if (stk.empty()) {
            ret = ((dp[i]=arr[i]*(i+1)%M)+ret)%M;
        } else {
            dp[i] += arr[i]*(i-stk.top())%M;
            dp[i] = (dp[i]+dp[stk.top()])%M;
            ret = (dp[i]+ret)%M;
        }
        stk.push(i);
    }

    return ret;
}

int main() {
    vector<int> v = {11,81,94,43,3};
    cout << sumSubarrayMins(v);

    return 0;
}