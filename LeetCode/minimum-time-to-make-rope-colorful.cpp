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

int minCost(string colors, vector<int>& neededTime) {
    int n = colors.length();
    if (n == 1) return 0;
    int ret = 0, mx = neededTime[0];

    for (int i = 1; i < n; i++) {
        if (colors[i] != colors[i-1]) {
            mx = neededTime[i];
        } else {
            if (mx > neededTime[i]) {
                ret += neededTime[i];
            } else {
                ret += mx;
                mx = neededTime[i];
            }
        }
    }

    return ret;
}

int main() {
    vector<int> v = {1,2,3,4,1};
    cout << minCost("aabaa", v);

    return 0;
}