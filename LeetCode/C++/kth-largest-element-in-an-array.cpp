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

unordered_map<int, int> mp;

int findKthLargest(vector<int>& nums, int k) {
    int mx = INT_MIN, mi = INT_MAX;
    for (int x : nums) {
        mp[x]++;
        mx = max(mx, x);
        mi = min(mi, x);
    }
    for (int i = mx; i >= mi; i--) {
        if (!mp.count(i)) {continue;}
        else if (k-mp[i] > 0) {k -= mp[i];}
        else {return i;}
    }

    return INT_MIN;
}

int main() {
    vector<int> v = {3,2,3,1,2,4,5,5,6};
    cout << findKthLargest(v, 4);

    return 0;
}