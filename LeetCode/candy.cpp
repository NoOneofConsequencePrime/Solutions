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

int candy(vector<int>& ratings) {
    if (ratings.size() == 1) return 1;
    int n = ratings.size(), cnt[n]; fill(cnt, cnt+n, 1);
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i-1]) cnt[i] = cnt[i-1]+1;
    }
    for (int i = n-2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1]) cnt[i] = max(cnt[i], cnt[i+1]+1);
    }

    int ret = 0;
    for (int& x : cnt) ret += x;

    return ret;
}

int main() {
    vector<int> v = {1,3,4,5,2};
    cout << candy(v);

    return 0;
}