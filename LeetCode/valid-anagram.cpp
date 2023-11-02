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

bool isAnagram(string s, string t) {
    int cnt[26] = {0};
    for (char c : s) cnt[c-'a']++;
    for (char c : t) cnt[c-'a']--;
    for (int i = 0; i < 26; i++) if (cnt[i]) return false;

    return true;
}

int main() {
    cout << isAnagram("anagram", "nagaram");

    return 0;
}