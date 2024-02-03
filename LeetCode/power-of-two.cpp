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
    bool isPowerOfTwo(int n) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        return n > 0 && __builtin_popcount(n) == 1;
    }
};

int main() {
    Solution ans;
    cout << ans.isPowerOfTwo(16);

    return 0;
}