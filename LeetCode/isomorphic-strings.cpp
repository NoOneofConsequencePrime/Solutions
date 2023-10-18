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

bool chk(string s, string t) {
    unordered_map<char, char> mp;
    for (int i = 0; i < s.length(); i++) {
        if (mp.count(s[i]) == 0) mp[s[i]] = t[i];
        else if (mp[s[i]] != t[i]) return false;
    }

    return true;
}

bool isIsomorphic(string s, string t) {
    return chk(s, t) && chk(t, s);
}

int main() {
    cout << isIsomorphic("paper", "turtle");

    return 0;
}