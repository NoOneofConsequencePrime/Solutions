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

vector<int> searchRange(vector<int>& nums, int target) {
    if (lower_bound(nums.begin(), nums.end(), target) == upper_bound(nums.begin(), nums.end(), target)) return {-1, -1};
    return {(int)(lower_bound(nums.begin(), nums.end(), target)-nums.begin()), (int)(upper_bound(nums.begin(), nums.end(), target)-nums.begin()-1)};
}

int main() {
    vector<int> v = {5,7,7,8,8,10};
    vector<int> ans = searchRange(v, 6);
    printf("%d, %d\n", ans[0], ans[1]);

    return 0;
}