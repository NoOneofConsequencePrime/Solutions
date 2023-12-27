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
    int ret = 0, mx = neededTime[0], tot = mx;

    for (int i = 1; i < n; i++) {
        if (colors[i] != colors[i-1]) {
            ret += tot-mx;
            mx = neededTime[i]; tot = mx;
            printf("A: %d", i);
        } else {
            mx = max(mx, neededTime[i]);
            tot += neededTime[i];
            printf("B: %d", i);
        }
        printf(" - (%d, %d, %d)\n", mx, tot, ret);
    }
    ret += tot-mx;

    return ret;
}

int main() {
    vector<int> v = {1,2,3,4,1};
    cout << minCost("aabaa", v);

    return 0;
}