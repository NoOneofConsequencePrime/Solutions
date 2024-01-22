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

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> ret = {0, n*(n+1)/2-nums[0]};
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i-1]) {ret[0] = nums[i];}
        else {ret[1] -= nums[i];}
    }

    return ret;
}

int main() {
    vector<int> v = {1,2,2,4};
    vector<int> ans = findErrorNums(v);
    printf("%d %d\n", ans[0], ans[1]);

    return 0;
}