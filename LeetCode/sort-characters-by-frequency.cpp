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
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> ppi;
typedef pair<ll, ll> pll;
#define f first
#define s second

//ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

class Solution {
private:
    int cnt[70];
public:
    string frequencySort(string s) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {cnt[c-'A']++;}
            else if (c >= 'a' && c <= 'z') {cnt[c-'a'+26]++;}
            else {cnt[c-'0'+26*2]++;}
        }
        vector<pair<int, char>> v;
        for (int i = 0; i < 26*2+10; i++) {
            if (cnt[i] != 0) {
                if (i < 26) {v.push_back({cnt[i], i+'A'});}
                else if (i < 26*2) {v.push_back({cnt[i], i-26+'a'});}
                else {v.push_back({cnt[i], i-26*2+'0'});}
            }
        }
        sort(v.begin(), v.end(), greater<pair<int, char>>());

        string ret = "";
        for (auto &[a, c] : v) {
            while (a--) {ret.push_back(c);}
        }

        return ret;
    }
};

int main() {
    Solution ans;
    cout << ans.frequencySort("tree");

    return 0;
}