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
    unordered_map<char, int> mp;
    for (char c : s) mp[c]++;
    for (char c : t) {
        mp[c]--;
        if (mp[c] < 0) return false;
        else if (mp[c] == 0) mp.erase(c);
    }

    return mp.size() == 0;
}

int main() {
    cout << isAnagram("anagram", "nagaram");

    return 0;
}