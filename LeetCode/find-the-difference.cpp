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

char findTheDifference(string s, string t) {
    unordered_map<char, int> um;
    for (char& c : s) um[c]++;
    for (char& c : t) {
        um[c]--;
        if (um[c] == -1) return c;
    }

    return ' ';
}

int main() {
    cout << findTheDifference("", "y");

    return 0;
}