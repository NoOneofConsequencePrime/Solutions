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
unordered_map<int, int> mp;

int longestArithSeqLength(vector<int>& nums) {
    int ret = 0;
    for (int chg = -mx; chg <= mx; chg++) {
        mp.clear();
        for (int x : nums) {
            if (mp.count(x-chg) != 0) {
                mp[x] = max(mp[x], mp[x-chg]+1);
                ret = max(ret, mp[x]);
            }
            if (mp.count(x) == 0) mp[x] = 1;
        }
    }

    return ret;
}

int main() {
    vector<int> v = {20,1,15,3,10,5,8};
    cout << longestArithSeqLength(v);

    return 0;
}