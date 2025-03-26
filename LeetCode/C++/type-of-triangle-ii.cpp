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
    string triangleType(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        sort(nums.begin(), nums.end());
        if (nums[0]+nums[1] <= nums[2]) {return "none";}
        else if (nums[0] == nums[1] && nums[1] == nums[2]) {return "equilateral";}
        else if (nums[0] == nums[1] || nums[1] == nums[2]) {return "isosceles";}
        else {return "scalene";}
    }
};

int main() {

    return 0;
}