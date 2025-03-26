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

const int MM = 501;
int dp[MM][MM];

int paintWalls(vector<int>& cost, vector<int>& time) {
    vector<pair<int, int>> v;
    int n = cost.size();
    for (int i = 0; i < n; i++) v.push_back({cost[i], time[i]});
    sort(v.begin(), v.end());

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i < n-len+1; i++) {
            int j = i+len-1;
            if (len == 1) {
                dp[i][j] = v[i].first; continue;
            } else if (len == 2) {
                dp[i][j] = min(v[i].first(), v[j].first); continue;
            }

            for (int idx = i; idx <= j-1; idx++) {
                
            }
        }
    }
}

int main() {
    vector<int> a = {1,2,3,2}, b = {1,2,3,2};
    cout << paintWalls(a, b);

    return 0;
}