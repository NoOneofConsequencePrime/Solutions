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

int cnt[30];

int minSteps(string s, string t) {
    int ret = 0;
    for (char c : s) {cnt[c-'a']++;}
    for (char c : t) {
        cnt[c-'a']--;
        if (cnt[c-'a'] < 0) {ret++;}
    }

    return ret;
}

int main() {
    cout << minSteps("leetcode", "practice");

    return 0;
}