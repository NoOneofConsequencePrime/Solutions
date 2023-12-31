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

int maxLengthBetweenEqualCharacters(string s) {
    int ret = -1, prev[26]; memset(prev, 0x3f, sizeof(prev));
    for (int i = 0; i < s.length(); i++) {
        if (prev[s[i]-'a'] <= 300) ret = max(ret, i-prev[s[i]-'a']-1);
        if (prev[s[i]-'a'] > 300) prev[s[i]-'a'] = i;
    }

    return ret;
}

int main() {
    cout << maxLengthBetweenEqualCharacters("abca");

    return 0;
}