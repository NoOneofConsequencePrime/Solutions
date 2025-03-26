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
    long long largestPerimeter(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        sort(nums.begin(), nums.end(), greater<int>());
        ll ret = 0;
        for (int x : nums) {ret += x;}
        int i = 0;
        for (; i < nums.size(); i++) {
            if (ret-nums[i] <= nums[i]) {ret -= nums[i];}
            else {break;}
        }
        
        if (nums.size()-i >= 3) {return ret;}
        else {return -1;}
    }
};

int main() {
    Solution ans;
    vector<int> v = {1,12,1,2,5,50,3};
    cout << ans.largestPerimeter(v);

    return 0;
}