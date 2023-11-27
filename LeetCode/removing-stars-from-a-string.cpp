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

string removeStars(string s) {
    int idx = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '*') {
            idx--;
        } else {
            s[idx] = s[i];
            idx++;
        }
    }

    return s.substr(0, idx);
}

int main() {
    cout << removeStars("leet**cod*e");

    return 0;
}