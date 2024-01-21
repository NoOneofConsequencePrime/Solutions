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

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) {return nums[0];}
    else if (n <= 2) {return max(nums[0], nums[1]);}
    int prev2 = nums[0], prev1 = max(nums[0], nums[1]), ret = prev1;
    for (int i = 2; i < n; i++) {
        int cur = nums[i]+prev2;
        ret = max(ret, cur);
        prev2 = prev1;
        prev1 = ret;
    }

    return ret;
}

int main() {
    vector<int> v = {2,7,9,3,1};
    cout << rob(v);

    return 0;
}