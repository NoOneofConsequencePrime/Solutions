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
const int MM = 5002;
int dp[MM];

int change(int amount, vector<int>& coins) {
    dp[0] = 1;
    for (int coin : coins) {
        for (int i = 0; i <= amount; i++) {
            if (dp[i] > 0 && i+coin <= amount) {dp[i+coin] += dp[i];}
        }
    }

    return dp[amount];
}

int main() {
    vector<int> v = {1,2,5};
    cout << change(5, v);

    return 0;
}