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

bool isSubsequence(string s, string t) {
    int idx = 0;
    for (char& a : s) {
        bool flag = true;
        for (; flag && idx < t.length(); idx++) flag = !(a == t[idx]);
        if (flag) return false;
    }

    return true;
}

int main() {
    cout << isSubsequence("abc", "uuuuuuuabc");

    return 0;
}