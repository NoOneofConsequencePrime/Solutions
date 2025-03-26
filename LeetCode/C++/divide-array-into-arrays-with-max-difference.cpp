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
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i*3+2 < n; i++) {
            if (nums[i*3+2]-nums[i*3] > k) {return {};}
            ret.push_back({nums[i*3], nums[i*3+1], nums[i*3+2]});
        }

        return ret;
    }
};

int main() {
    Solution ans;
    vector<int> v = {1,3,4,8,7,9,3,5,1};
    vector<vector<int>> ret = ans.divideArray(v, 2);
    for (auto v : ret) {
        for (int x : v) {cout << x << " ";}
        cout << endl;
    }

    return 0;
}