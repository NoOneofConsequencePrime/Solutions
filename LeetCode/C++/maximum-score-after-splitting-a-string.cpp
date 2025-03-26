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

int maxScore(string s) {
    int zc = 0;
    for (int i = 0; i < s.length(); i++) zc += (s[i] == '0');

    int ret = INT_MIN;
    if (zc == 0 || zc == s.length()) return s.length()-1;
    for (int i = 0, cnt = 0; i < s.length()-1; i++) {
        if (s[i] == '0') cnt++;
        ret = max(ret, (int)(cnt + s.length()-(i+1)-(zc-cnt)));
    }

    return ret;
}

int main() {
    cout << maxScore("11100");

    return 0;
}