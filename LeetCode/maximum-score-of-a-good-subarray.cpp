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

int maximumScore(vector<int>& nums, int k) {
    int ret = -1;
    vector<int> pre(k+1), suf(nums.size()-k);
    copy(nums.begin(), nums.begin()+k+1, pre.begin());
    copy(nums.begin()+k, nums.end(), suf.begin());

    for (int i = k-1; i >= 0; i--) pre[i] = min(pre[i], pre[i+1]);
    for (int i = 1; i < suf.size(); i++) suf[i] = min(suf[i], suf[i-1]);

    for (int i = 0; i < suf.size(); i++) {
        int idx = pre.size()-(lower_bound(pre.begin(), pre.end(), suf[i])-pre.begin());
        int prod = (idx+i)*suf[i];
        ret = max(ret, prod);
        // printf("%d\n", ret);
    }
    for (int i = k; i >= 0; i--) {
        int idx = (upper_bound(suf.begin(), suf.end(), pre[i], greater<int>())-suf.begin());
        int prod = (idx+(k-i))*pre[i];
        ret = max(ret, prod);
        // printf("%d\n", ret);
    }

    // for (auto x : pre) cout << x << " ";
    // cout << endl;
    // for (auto x : suf) cout << x << " ";
    // cout << endl;

    return ret;
}

int main() {
    vector<int> v = {1,4,3,7,4,5};
    // 1 4 3 7 4 5
    // 1 3 3 7
    // - - - 7 4 4
    cout << maximumScore(v, 3);

    return 0;
}