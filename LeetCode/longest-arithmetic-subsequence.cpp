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

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int mx = 500;
int cnt[mx+2];

int longestArithSeqLength(vector<int>& nums) {
    int ret = 0;
    for (int chg = -mx; chg <= mx; chg++) {
        memset(cnt, 0, sizeof(cnt));
        for (int x : nums) {
            if (x-chg >= 0 && x-chg <= 500 && cnt[x-chg] != 0) {
                cnt[x] = max(cnt[x], cnt[x-chg]+1);
                ret = max(ret, cnt[x]);
            }
            if (cnt[x] == 0) cnt[x] = 1;
        }
    }

    return ret;
}

int main() {
    vector<int> v = {24,13,1,100,0,94,3,0,3};
    cout << longestArithSeqLength(v);

    return 0;
}