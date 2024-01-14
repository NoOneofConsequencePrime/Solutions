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

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int cnt1[30], cnt2[30];
unordered_map<int, int> mp;

bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length()) return false;
    
    int n = word1.length();
    for (int i = 0; i < n; i++) {
        cnt1[word1[i]-'a']++; cnt2[word2[i]-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt1[i]>0 && cnt2[i]==0) {return false;}
        if (cnt1[i]==0 && cnt2[i]>0) {return false;}

        if (cnt1[i] > 0) {mp[cnt1[i]]++;}
        if (cnt2[i] > 0) {mp[cnt2[i]]--;}
    }

    for (auto [f, s] : mp) {
        if (s != 0) {return false;}
    }

    return true;
}

int main() {
    cout << closeStrings("cabbba", "abbccc");

    return 0;
}