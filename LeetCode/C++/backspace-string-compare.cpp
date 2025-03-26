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

bool backspaceCompare(string s, string t) {
    vector<char> a, b;
    for (char& c : s) {
        if (c == '#' && a.size() > 0) a.pop_back();
        else if (c != '#) a.push_back(c);
    }
    for (char& c : t) {
        if (c == '#' && b.size() > 0) b.pop_back();
        else if (c != '#) b.push_back(c);
    }

    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

int main() {
    cout << backspaceCompare("y#fo##f", "y#f#o##f");

    return 0;
}