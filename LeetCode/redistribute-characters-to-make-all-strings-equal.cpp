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

bool makeEqual(vector<string>& words) {
    int cnt[26] = {0};
    for (string str : words) {
        for (char c : str) cnt[c-'a']++;
    }

    int n = words.size();
    for (int i = 0; i < 26; i++) {
        if (cnt[i]%n != 0) return false;
    }
    
    return true;
}

int main() {

    return 0;
}