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
    vector<int> ret = {0, n*(n+1)/2};
    vector<bool> chk(n+1, false);
    for (int x : nums) {
        if (!chk[x]) {
            chk[x] = true;
            ret[1] -= x;
        } else {
            ret[0] = x;
        }
    }

    return ret;
}

int main() {
    vector<int> v = {1,1};
    vector<int> ans = findErrorNums(v);
    printf("%d %d\n", ans[0], ans[1]);

    return 0;
}