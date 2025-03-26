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

string longestCommonPrefix(vector<string>& strs) {
    string ret = "";
    for (int i = 0; i >= 0; i++) {
        for (string& str : strs) {
            if (i >= str.length()) {
                i = INT_MIN; break;
            } else if (str[i] != strs[0][i]) {
                i = INT_MIN; break;
            }
        }
        if (i >= 0) ret += strs[0][i];
    }

    return ret;
}

int main() {
    vector<string> v = {"flower","flow","flight"};
    cout << longestCommonPrefix(v);

    return 0;
}