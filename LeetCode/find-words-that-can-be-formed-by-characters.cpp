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

int countCharacters(vector<string>& words, string chars) {
    int chk[26] = {0}, cnt[26] = {0}, ret = 0;
    for (char c : chars) chk[c-'a']++;

    for (string str : words) {
        memset(cnt, 0, sizeof(cnt));
        bool flag = true;
        for (char c : str) {
            cnt[c-'a']++;
            if (cnt[c-'a'] > chk[c-'a']) flag = false;
        }
        if (flag) ret += str.length();
    }

    return ret;
}

int main() {
    vector<string> v = {"hello","world","leetcode"};
    cout << countCharacters(v, "welldonehoneyr");

    return 0;
}