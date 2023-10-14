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
    int cnt[26]; memset(cnt, 0, sizeof(cnt));
    for (char& c : magazine) cnt[c-'a']++;
    for (char& c : ransomNote) if (cnt[c-'a']-- <= 0) return false;

    return true;
}

int main() {
    cout << canConstruct("aa", "aab");

    return 0;
}