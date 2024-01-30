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
public:
    int minimumPushes(string word) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int cnt[28] = {};
        for (char c : word) {cnt[c-'a']++;}
        vector<int> v;
        for (int i = 0; i < 26; i++) {v.push_back(cnt[i]);}
        sort(v.begin(), v.end(), greater<int>());
        
        int ret = 0;
        for (int i = 0; i < 8; i++) {ret += v[i];}
        for (int i = 8; i < 16; i++) {ret += 2*v[i];}
        for (int i = 16; i < 24; i++) {ret += 3*v[i];}
        for (int i = 24; i < 26; i++) {ret += 4*v[i];}
        
        return ret;
    }
};

int main() {
    Solution ans;
    cout << ans.minimumPushes("xycdefghij");

    return 0;
}