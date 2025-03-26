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
    int missingNumber(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = nums.size(), ret = n*(n+1)/2;
        for (int x : nums) {ret -= x;}
        
        return ret;
    }
};

int main() {
    Solution ans;
    vector<int> v = {9,6,4,2,3,5,7,0,1};
    cout << ans.missingNumber(v);

    return 0;
}