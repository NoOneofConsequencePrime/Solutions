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

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> um;
    for (char& c : magazine) um[c]++;
    for (char& c : ransomNote) if (um[c]-- <= 0) return false;

    return true;
}

int main() {
    cout << canConstruct("aa", "aab");

    return 0;
}