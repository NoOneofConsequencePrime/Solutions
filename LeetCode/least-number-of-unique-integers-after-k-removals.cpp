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
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        unordered_map<int, int> mp;
        for (int x : arr) {mp[x]++;}
        vector<pii> v;
        for (auto &[a, b] : mp) {
            v.push_back({b, a});
        }
        sort(v.begin(), v.end());

        int n = v.size(), i = 0;
        for (; i < n; i++) {
            if (v[i].f > k) {break;}
            k -= v[i].f;
        }

        return max(0, n-i);
    }
};

int main() {

    return 0;
}