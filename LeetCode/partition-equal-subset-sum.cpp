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

const int MM = 1e4+2;
bool dp[MM];

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int x : nums) {sum += x;}
    if (sum%2) {return false;}
    sum /= 2;

    dp[0] = true;
    for (int num : nums) {
        for (int i = sum; i >= 1; i--) {
            if (i-num >= 0 && dp[i-num]) {dp[i] = true;}
        }
    }

    return dp[sum];
}

int main() {
    vector<int> v = {1,5,11,5};
    cout << canPartition(v);

    return 0;
}