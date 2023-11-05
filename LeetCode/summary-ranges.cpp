#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_set>
#include <numeric>
using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ret;
    if (nums.size() == 0) return ret;
    else if (nums.size() == 1) {
        ret.push_back(to_string(nums[0]));
        return ret;
    }

    int j = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i]-1 != nums[i-1]) {
            if (j == nums[i-1]) ret.push_back(to_string(j));
            else ret.push_back(to_string(j)+"->"+to_string(nums[i-1]));
            j = nums[i];
        }
    }
    if (j == nums.back()) ret.push_back(to_string(j));
    else ret.push_back(to_string(j)+"->"+to_string(nums.back()));

    return ret;
}

int main() {
    vector<int> v = {0,1,2,4,5,7};
    vector<string> ans = summaryRanges(v);
    for (auto x : ans) cout << x << '\n';

    return 0;
}