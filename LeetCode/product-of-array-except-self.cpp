#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
using namespace std;

int qPow(int b, int e) {
    int ret = 1;
    while (e > 0) {
        if ((e&1) == 1) ret *= b;
        e >>= 1;
        if (e != 0) b *= b;
    }
    return ret;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int cnt[61]; memset(cnt, 0, sizeof(cnt));
    for (int& x : nums) cnt[x+30]++;

    vector<int> ret;
    for (int& x : nums) {
        int tmp = 1;
        for (int i = 0; i <= 60; i++) {
            if (i-30 == x) {
                if (cnt[i] >= 2) tmp *= qPow(i-30, cnt[i]-1);
            } else if (cnt[i] >= 1) tmp *= qPow(i-30, cnt[i]);
        }
        ret.push_back(tmp);
    } 

    return ret;
}

int main() {
    vector<int> v = {-1,1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,1,1,-1,-1,1};
    vector<int> ans = productExceptSelf(v);
    for (auto& x : ans) cout << x << " ";

    return 0;
}